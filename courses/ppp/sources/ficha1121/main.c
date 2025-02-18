#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "myQueue.h"

#define sizeArray 500

void array2Queue(int array[], typeQueue *simpleQueueptr){
    struct myItem element;

    for (int i=0; i < sizeArray; i++){
        element.isNull = 0;
        element.item = array[i];
        addItem(simpleQueueptr, element);
    }
}

int main() {
    int array[sizeArray];
    typeQueue simpleQueue;
    typeQueue *simpleQueueptr = &simpleQueue;

    srand(time(NULL));
    createQueue(simpleQueueptr);

    for (int i=0; i < sizeArray; i++)
        array[i] = rand();

    array2Queue(array, simpleQueueptr);

    //Print elements (numbers) in the queue
    itemQueue *current = simpleQueueptr->first;

    while (current != NULL){
        printf("Output: %d\n", current->myItemQueue.item);
        current = current->next;
    }

    destroyQueue(simpleQueueptr);

    return 0;
}
