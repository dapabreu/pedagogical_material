//compile with: gcc -Wall sharedvariable_sysv.c semlib.c -o svar
//using SysV semaphores

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "semlib.h"

int * shared_var;
int shmid, semid;

void worker()
	{
	usleep(1000000 + rand()%11*100000); //uses microseconds sleep and waits 1 to 2 seconds in periods of 0.1 secs
	sem_wait(semid, 0);
	(*shared_var)++;
	sem_post(semid, 0);
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

	if ((semid = sem_get(1, 1)) == -1) {
		perror("Failed to initialize semaphore");
		exit(1);
	}

	*shared_var=1000; // initialize variable in shared memory

	for(i=0;i<n_procs;i++){
		if(fork()==0){
			printf("Worker %d created and ready for business!\n",getpid());
			worker();
			printf("Worker %d leaving!\n",getpid());
			exit(0);
			}
		}
	for(i=0;i<n_procs;i++) wait(NULL); // parent waits for all children
	
	// print final result
	printf("Final result= %d\n",*shared_var);

	// remove resources
	sem_close(semid);
	shmdt(shared_var);
	shmctl(shmid,IPC_RMID,NULL);	

	exit(0);
}
