//
// Created by david on 09/04/2023.
//

#ifndef PRIORITYQUEUE_MYQUEUE_H
#define PRIORITYQUEUE_MYQUEUE_H

typedef struct nData{
    double data;
    int priority;
}typenD;

typedef struct nQueue{
    double data;
    int priority;
    struct nQueue *next;
} typenQ;

typedef struct Queue{
    typenQ *first;
    typenQ *last;
} typeQueue;

void createQueue(typeQueue *queue);
int emptyQueue(typeQueue *queue);
void destroyQueue(typeQueue *queue);
void addItem(typeQueue *queue, double ldata, int lpriority);
void addItemPriority(typeQueue *queue, double ldata, int lpriority);
typenD removeItem(typeQueue *queue);
typenD peekQueue(typeQueue *queue);
void printQueue(typeQueue *queue);

#endif //PRIORITYQUEUE_MYQUEUE_H
