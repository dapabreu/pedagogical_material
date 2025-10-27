//compile with: gcc -Wall -pthread sharedvariable_posix.c -o svar
//using POSIX named semaphores

//This version forces a ping-pong between producers and consumers - MUST BE CHANGED

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h> // include POSIX semaphores
#include <fcntl.h>     // For O_* constants
#include <sys/stat.h>

#define TICKETSIZE 6

int *shared_var;
int shmid;
sem_t *readers, *generator;

int check_ticket(int ticket[], int elements, int number){
	int i, exists = 0;
	for (i=0; i<elements; i++){
		if (ticket[i] == number){
			exists = 1;
			break;
		}
	}
	return exists;
}

void worker(int number){
	FILE *file;
	char filename [8];
	int ticket[TICKETSIZE], elements = 0, i;

	sprintf(filename, "key_%d", number);
	file = fopen(filename, "w");

	while (elements < TICKETSIZE){
		sem_wait(readers);
		if (!check_ticket(ticket, elements, *shared_var)){
			ticket[elements] = *shared_var;
			elements++;
			fprintf(file, "%d", *shared_var);
			if (elements < TICKETSIZE){
				fprintf(file, "\t");
			}
		}

		if (elements == TICKETSIZE){
			for (i=0; i<TICKETSIZE; i++){
				printf("%d", ticket[i]);
				if (i < TICKETSIZE-1)
					printf("\t");
			}
			printf("\n");
		}

		sem_post(generator);
	}

	fprintf(file, "\n");
	fclose(file);
}

void lottery(){
	while (1){
		sem_wait(generator);
		
		if (*shared_var == -1)
			break;

		*shared_var = rand()%49 + 1;

		sem_post(readers);
	}

}

int main(int argc, char *argv[])
	{
	int i, n_procs;

	if(argc!=2) {
		printf("Wrong number of parameters\n");
		exit(0);
		}

	n_procs=atoi(argv[1]);

	if ((shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0766)) < 0) {
		perror("Error in shmget with IPC_CREAT\n");
		exit(1);
	}

	if ((shared_var = (int *) shmat(shmid, NULL, 0)) == (int*)-1) {
		perror("Shmat error!");
		exit(1);
	}

	sem_unlink("READERS");
	sem_unlink("GENERATOR");
  	readers=sem_open("READERS",O_CREAT|O_EXCL,0700,0);
  	generator=sem_open("GENERATOR",O_CREAT|O_EXCL,0700,1);

	for(i=0;i<n_procs;i++){
		if(fork()==0){
			printf("Worker %d created and ready for business!\n",getpid());
			worker(i+1);
			printf("Worker %d leaving!\n",getpid());
			exit(0);
			}
		}

	*shared_var = 0; //initialize shared memory

	if (fork()==0){
		printf("Generator %d created and ready for business!\n",getpid());
		lottery();
		printf("Generator %d leaving!\n",getpid());
		exit(0);	
	}	

	for(i=0;i<n_procs;i++) wait(NULL); // parent waits for all workers to finish

	*shared_var = -1; //instruct generator to end
	sem_post(generator); //let generator process the end command

	wait(NULL); //wait for generator to end
	
	// remove resources
	sem_close(readers);
	sem_close(generator);
	sem_unlink("READERS");
	sem_unlink("GENERATOR");
	shmdt(shared_var);
	shmctl(shmid,IPC_RMID,NULL);	

	exit(0);
}
