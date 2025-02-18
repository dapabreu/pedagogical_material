#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myQueue.h"

#define numElements 10

int main(){
    typeQueue *simpleQueueptr;
    time_t t;

    //Creating the queue
    simpleQueueptr = (typeQueue *) malloc(sizeof(typeQueue));

    //Verifying malloc
    if (simpleQueueptr == NULL){
        printf("Memory not allocated on simpleQueueptr.\n");
        return -1;
    }

    createQueue(simpleQueueptr);

    //Add some elements to the queue
    srand((unsigned) time(&t)); //Initializing the seed for the random

    /*
    for (int i=0; i<numElements; i++)
        addItemPriority(simpleQueueptr, i, rand() % 5);
    */

    addItemPriority(simpleQueueptr, 1.0, 1);
    addItemPriority(simpleQueueptr, 2.0, 0);
    addItemPriority(simpleQueueptr, 3.0, 2);
    addItemPriority(simpleQueueptr, 4.0, 1);


    //Print the queue before destroy it
    printQueue(simpleQueueptr);
    //typenD aux = removeItem(simpleQueueptr);

    printf("\n-----  first ----\n");
    printf("Last -- Data: %lf -- Priority: %d\n", simpleQueueptr->first->data, simpleQueueptr->first->priority);

    printf("\n-----  last ----\n");
    printf("Last -- Data: %lf -- Priority: %d\n", simpleQueueptr->last->data, simpleQueueptr->last->priority);

    //printf("Priority: %d -- Data: %lf\n", aux.priority, aux.data);
    free(simpleQueueptr);

    return 0;
}


