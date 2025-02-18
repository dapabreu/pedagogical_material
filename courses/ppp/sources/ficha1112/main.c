#include <stdio.h>
#include <string.h>
#include "myQueue.h"

int main() {
    char string[100];
    typeQueue simpleQueue;
    typeQueue *simpleQueueptr = &simpleQueue;
    struct myItem element;

    createQueue(simpleQueueptr);

    while (1){
        printf("Please introduce a string:");
        scanf("%s",string);
        element.isNull = 0;
        strcpy(element.item,string);
        addItem(simpleQueueptr, element);
        if(strcmp(string,"FIM") == 0)
            break;
    }

    //Print elements in the queue
    itemQueue *current = simpleQueueptr->first;

    while (current != NULL){
        printf("Output: %s \n", current->myItemQueue.item);
        current = current->next;
    }

    destroyQueue(simpleQueueptr);

    return 0;
}
