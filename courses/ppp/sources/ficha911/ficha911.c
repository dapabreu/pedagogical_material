#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define minRand 0
#define maxRand 30
#define arraySize 10

void iniArray(float array[]);
void minmaxArray(float array[], float *min, float *max);
void printArray(float array[]);

int main(){
    srand(time(NULL));
    float array[arraySize];
    float a,b;
    float *min, *max;
    a = 1000000;
    b = -1;
    min= &a;
    max= &b;

    iniArray(array);
    minmaxArray(array, min, max);
    printArray(array);
    printf("The Min and Max values in the array are: %f and %f\n",*min,*max);
    return 0;
}

// Function to initialize the array
void iniArray(float array[]){
    for(int i=0; i < arraySize; i++)
        array[i] = (maxRand-minRand) * ((float)rand()/(float)(RAND_MAX)) + minRand;
}

// Min and Max elements in the Array
void minmaxArray(float array[], float *min, float *max){
    for (int i=0; i<arraySize; i++){
        if (array[i]<*min)
            *min= array[i];
        if (array[i]>*max)
            *max= array[i];
    }
}

// Function to print an array
void printArray(float array[]){
    for (int i=0; i < arraySize; i++)
        printf("%f ", array[i]);
    printf("\n");
}
