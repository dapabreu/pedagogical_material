#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define PIPE_NAME   "my_pipe"

char str[256];
int fd_named_pipe,fd_temp[2],fd_hum[2]; // to save file descriptors
int temp_sum, temp_samples, hum_sum, hum_samples; // to save temperature and humidity sum and number of samples
int value;
int pid[2]; // saves the pid of child processes

void clean_resources(){ // cleans all resources including closing of files
	close(fd_named_pipe);
	close(fd_temp[0]);
	close(fd_temp[1]);	
	close(fd_hum[0]);
	close(fd_hum[1]);
	
	unlink(PIPE_NAME);
	}
	
void sigint(int signum) { // handling of CTRL-C
	printf("\n\n\n^C pressed. Cleaning resources...\n");
	clean_resources();
	printf("Bye bye\n");
	exit(0);
	}

void shutdown_all(){
	kill(pid[0], SIGKILL);
	kill(pid[1], SIGKILL);
	while (wait(NULL) != -1);
	clean_resources();
	printf("Bye bye\n");
	exit(0);
	}

void measure_temp() { // generates temperature values and writes them in the corresponding pipe
	close(fd_temp[0]);	
	close(fd_hum[0]);
	close(fd_hum[1]);
	srand(getpid());
	while(1){
		value=10+rand()%31; //temperature between 10-40
		write(fd_temp[1],&value,sizeof(int));
		sleep(3);
		}
	}

void measure_humidity() { // generates humidity values and writes them in the corresponding pipe
	close(fd_hum[0]);	
	close(fd_temp[0]);
	close(fd_temp[1]);
	srand(getpid());
	while(1){
		value=50+rand()%51; //humidity between 50-100
		write(fd_hum[1],&value,sizeof(int));
		sleep(3);
		}
	}


int main()
{
  int number_of_chars;
  fd_set read_set;

  // Server terminates when CTRL-C is pressed
  // Redirect CTRL-C
  signal(SIGINT, sigint);  // CTRL-C

  //create pipes
  pipe(fd_temp);
  pipe(fd_hum);

  //create childs
  if((pid[0]=fork())==0){
	measure_temp();
	exit(0);
	}
  if((pid[1]=fork())==0){
	measure_humidity();
	exit(0);
	}

  // Creates the named pipe if it doesn't exist yet
  if ((mkfifo(PIPE_NAME, O_CREAT|O_EXCL|0600)<0))
  {
    perror("Cannot create pipe: ");
    exit(0);
  }

  // Opens the pipe for reading
  if ((fd_named_pipe=open(PIPE_NAME, O_RDWR)) < 0)
  {
    perror("Cannot open pipe for reading: ");
    exit(0);
  }

//printf("sizeofstr %d",sizeof(str));

  // Listen to messages

  printf("Listening to all pipes!\n\n");
  while (1) {
	FD_ZERO(&read_set);
	FD_SET(fd_temp[0],&read_set);
	FD_SET(fd_hum[0],&read_set);
	FD_SET(fd_named_pipe,&read_set);

	if(select(fd_named_pipe+1,&read_set,NULL,NULL,NULL)>0){
		if(FD_ISSET(fd_named_pipe,&read_set)){
			number_of_chars=read(fd_named_pipe, str, sizeof(str));
			str[number_of_chars-1]='\0'; //put a \0 in the end of string
			//printf("[SERVER Received %d chars]: %s\n", number_of_chars,str);
			if(strcmp(str,"AVG TEMP")==0)
				printf("[SERVER Received \"%s\" command]\nAverage Temperature= %.2fºC\n", str,(double)temp_sum/temp_samples);
				else
				if(strcmp(str,"AVG HUM")==0)
					printf("[SERVER Received \"%s\" command]\nAverage Humidity= %.2f %%\n", str,(double)hum_sum/hum_samples);
					else
					if(strcmp(str,"RESET")==0){
						printf("[SERVER received \"%s\" command]\nCounters reset!\n", str);
						temp_sum=0;
						temp_samples=0;
						hum_sum=0;
						hum_samples=0;
						}
						else
						if(strcmp(str,"SHUTDOWN")==0){
							printf("[SERVER received \"%s\" command]\nServer shutdown initiated!\n", str);
							shutdown_all();
							}
							else
							printf("[SERVER Received unknown command]: %s \n",str);
			} // if(FD_ISSET(fd_named_pipe))
		if(FD_ISSET(fd_temp[0],&read_set)){
			read(fd_temp[0], &value, sizeof(int));
			printf("[SERVER received new temperature]: %dºC\n", value);
			temp_sum+=value;
			temp_samples++;
			}
		if(FD_ISSET(fd_hum[0],&read_set)){
			read(fd_hum[0], &value, sizeof(int));
			printf("[SERVER received new humidity]: %d %% \n", value);
			hum_sum+=value;
			hum_samples++;
			}
 	 	} // if(select...
	} // While(1)
  return 0;
}
