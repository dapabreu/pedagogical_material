//
// Created by david on 09/04/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"

void createQueue (typeQueue *queue){
    queue->first = NULL;
    queue->last = NULL;
}

int emptyQueue(typeQueue *queue){
    if(queue->first == NULL)
        return 1;
    else
        return 0;
}

void destroyQueue(typeQueue *queue){
    typenQ *temp_ptr;
    while(!emptyQueue(queue)){
        temp_ptr = queue->first;
        queue->first = queue->first->next;
        free(temp_ptr);
    }
    queue->last = NULL;
}

void addItem(typeQueue *queue, double ldata, int lpriority){
    typenQ *temp_ptr;
    temp_ptr = (typenQ *) malloc(sizeof(typenQ));
    if(temp_ptr != NULL){
        temp_ptr->data = ldata;
        temp_ptr->priority = lpriority;
        temp_ptr->next = NULL;
        if(emptyQueue(queue))
            queue->first = temp_ptr;
        else
            queue->last->next = temp_ptr;
        queue->last = temp_ptr;
    }
}

void addItemPriority(typeQueue *queue, double ldata, int lpriority){
    typenQ *temp_ptr;
    typenQ *current;
    temp_ptr = (typenQ *) malloc(sizeof(typenQ));
    if(temp_ptr != NULL){
        temp_ptr->data = ldata;
        temp_ptr->priority = lpriority;
        temp_ptr->next = NULL;
        if(emptyQueue(queue)) {
            queue->first = temp_ptr;
            queue->last = temp_ptr;
        }else{
            current = queue->first;
            if (current->priority > temp_ptr->priority){
                temp_ptr->next = queue->first;
                queue->first = temp_ptr;
            }else{
                while ((current->next != NULL) && (current->next->priority <= temp_ptr->priority))
                    current = current->next;
                temp_ptr->next = current->next;
                current->next = temp_ptr;
                if (temp_ptr->next == NULL)
                    queue->last = temp_ptr;
            }
        }
    }
}

typenD removeItem(typeQueue *queue){
    typenQ *temp_ptr;
    typenD item = {-1.0, -1};
    if(!emptyQueue(queue)){
        temp_ptr = queue->first;
        item.data = temp_ptr->data;
        item.priority = temp_ptr->priority;
        queue->first = queue->first->next;
        if(emptyQueue(queue))
            queue->last = NULL;
        free(temp_ptr);
        return (item);
    }
    return (item);
}

typenD peekQueue(typeQueue *queue){
    typenD item = {-1.0, -1};
    if(!emptyQueue(queue)){
        item.data = queue->first->data;
        item.priority = queue->first->priority;
        return (item);
    }
    else
        return(item);
}

void printQueue(typeQueue *queue){
    typenQ *current = queue->first;
    int i = 0;

    if (current != NULL){
        printf("+++++\n");
        while (current != NULL) {
            printf("Item: %d -- Data: %lf -- Priority: %d\n", i, current->data, current->priority);
            printf("+++++\n");
            current = current->next;
            i++;
        }
    }else{
        printf("The Queue is empty!\n");
    }
}
