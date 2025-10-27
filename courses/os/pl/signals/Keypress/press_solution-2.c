// Solution 2 - the same handler function to both signals

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int t_ini,num;

void handler_function(int signum) {
  if(signum==SIGTSTP){
    char option[2];
    printf("\n\n\n^Z pressed. Do you want to abort? (y=yes)");

    scanf("%1s", option);
    if (option[0] == 'y') {
      printf("\nOk, bye bye!\n\n");
      exit(0);
    }
  }
  if(signum==SIGINT){
    int t_end;
    signal(SIGINT,SIG_IGN); //ignores the SIGINT (CTRL-C)
    t_end=time(NULL);
    printf("\n\n=> %d seconds elapsed! ",t_end-t_ini);
    if(t_ini+num>t_end) printf("You were too fast...\n");
      else
	    if(t_ini+num<t_end) printf("You were too slow...\n");
	      else printf("Great shot!\n");
    printf("\n\nPress ENTER to continue!");
    while(getc(stdin)!=10);
    }
  }

int main() {
  signal(SIGINT,SIG_IGN);   // Ignores the SIGINT (CTRL-C)
  signal(SIGTSTP, handler_function); // Redirects CTRL-Z

  // Do some work!
  srand(time(NULL));
  while (1) {
	  num=rand()%8+2;
	  printf("\n\nPress CTRL-C in %d seconds!\nCountdown starting in 2 seconds... Get Ready!!\n",num);
	  sleep(2);
	  signal(SIGINT, handler_function); //redirects the SIGINT again (CTRL-C) in order to be able to play the game
	  printf("Start counting the seconds!!\n");
	  t_ini=time(NULL);
    pause();
	}
  return 0;
}
