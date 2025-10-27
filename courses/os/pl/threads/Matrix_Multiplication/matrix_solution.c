// Compile as: gcc matrix_solution.c -lpthread -D_REENTRANT -Wall -o matrix

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define M 3 //first matrix lines
#define K 2 //first matrix columns; second matrix lines
#define N 3 //second matrix columns

struct v {
  int row;
  int column;
};

typedef struct v coordenate;
void *worker(void* coord);
void *show_matrix();	// prints matrices on screen

pthread_t my_thread[(M*N)+1];
int A[M][K] = { {1,4}, {2,5}, {3,6} };
int B[K][N] = { {8,7,6}, {5,4,3} };
int C[M][N];

// create mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void print_matrix(){ // prints matrices on screen when having exclusive access
    int i, j;
    pthread_mutex_lock(&mutex);
    i=j=0;
    //Print matrices
    printf("\nMatrix_A x Matrix_B = Matrix_C\n");
    for (i = 0; i < M; i++) {
      for (j = 0; j < K; j++)
    	printf("%4d",A[i][j]);
      printf("\n");
      }
    printf("X\n");
    for (i = 0; i < K; i++) {
      for (j = 0; j < N; j++)
    	printf("%4d",B[i][j]);
      printf("\n");
      }
    printf("=\n");
    for (i = 0; i < M; i++) {
      for (j = 0; j < N; j++)
    	printf("%4d",C[i][j]);
      printf("\n");
      }
    pthread_mutex_unlock(&mutex);
}

int main(void) {
  // creates threads and sends each the coordinates of the element to calculate
  int i,j,c = 0;
  pthread_create(&my_thread[M*N], NULL, show_matrix, (void*)NULL);
  for (i = 0; i < M; i++)
    for (j = 0; j < N; j++) {
      coordenate *data = (coordenate *)malloc(sizeof(coordenate));
      data->row = i;
      data->column = j;
      pthread_create(&my_thread[c++], NULL, worker, data);
      printf("Thread %d created\n", c-1);
    }

  // waits for threads to finish
  for (i = 0; i < (M*N)+1; i++) {
    pthread_join(my_thread[i], NULL);
    printf("Thread %d joined\n", i);
  }

  // prints final results of the calculation and leaves
  printf("Final results...\n");
  print_matrix();
  pthread_exit(NULL);
  exit(0);
}


void *worker(void* coord) {
  // calculates each matrix element in the coordinate received
  coordenate data = *((coordenate*)coord);
  int n;
  printf("ZzZz Going to sleep for a random time\n");
  sleep(rand()%10);
  C[data.row][data.column]  = 0;
  for (n = 0; n < K; n++) {
    pthread_mutex_lock(&mutex);
    C[data.row][data.column] += A[data.row][n] * B[n][data.column];
    pthread_mutex_unlock(&mutex);
  }
  free(coord);
  pthread_exit(NULL);
  return NULL;
}

void *show_matrix() {
// prints the status of the matrix in each second, along a period of 10 seconds
  int z=0;
  while (z < 10) {
    print_matrix();
    sleep(1);
    ++z;
  }
  pthread_exit(NULL);
  return NULL;
}
