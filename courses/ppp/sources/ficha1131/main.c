#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"

void readElements(int* ptrArray, int size);
void array2Queue(int *array, int size, typeQueue *simpleQueueptr);

int main(){
    int size = -1;
    int *ptrArray;
    //typeQueue simpleQueue;
    typeQueue *simpleQueueptr; //= &simpleQueue;

    simpleQueueptr = (typeQueue *) malloc(sizeof(typeQueue));

    if (simpleQueueptr == NULL){
        printf("Memory not allocated.\n");
        exit(1);
    }

    createQueue(simpleQueueptr);

    printf("Enter # of elements: ");
    scanf("%d", &size);

    ptrArray = (int*) malloc(size * sizeof (int));

    if(ptrArray == NULL) {
        printf("Memory not allocated.\n");
        exit(1);
    }
    else{
        printf("Memory successfully allocated using malloc.\n");
        readElements(ptrArray, size);
        array2Queue(ptrArray, size, simpleQueueptr);

    }
    //Print elements (numbers) in the queue
    itemQueue *current = simpleQueueptr->first;

    while (current != NULL){
        printf("Item: %d -- Amount: %d\n", current->myItemQueue.item, current->myItemQueue.amount);
        current = current->next;
    }

    destroyQueue(simpleQueueptr);

    free(simpleQueueptr);
    free(ptrArray);

    return 0;
}

void readElements(int* ptrArray, int size){
    for(int i=0; i<size; i++){
        printf("Introduce the %d array element: ", i);
        scanf("%d",&ptrArray[i]);
    }
}

void array2Queue(int *array, int size, typeQueue *simpleQueueptr){
    struct myItem element;
    int *ptr;
    int *endptr = array + (size-1);
    int flag;

    for(ptr = array; ptr <=endptr; ptr++){
        flag = 0;
        if(emptyQueue(simpleQueueptr)){
            element.isNull = 0;
            element.amount = 1;
            element.item = *ptr;
            addItem(simpleQueueptr, element);
        }
        else{
            itemQueue *current = simpleQueueptr->first;
            while (current != NULL) {
                if (current->myItemQueue.item == *ptr) {
                    current->myItemQueue.amount++;
                    flag = 1;
                }
                current = current->next;
            }

            //First appearance of item
            if(!flag){
                element.isNull = 0;
                element.amount = 1;
                element.item = *ptr;
                addItem(simpleQueueptr, element);
            }
        }
    }
}
