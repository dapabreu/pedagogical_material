//
// Created by david on 25/04/2022.
//

#ifndef FICHA1112_MYQUEUE_H
#define FICHA1112_MYQUEUE_H

struct myItem{
    int isNull;
    char item[100];
};

typedef struct itemQueue{
    struct myItem myItemQueue;
    struct itemQueue *next;
} itemQueue;

typedef struct typeQueue{
    itemQueue *first;
    itemQueue *last;
} typeQueue;

void createQueue (typeQueue *queue);
int emptyQueue(typeQueue *queue);
void destroyQueue(typeQueue *queue);
void addItem(typeQueue *queue, struct myItem item);
struct myItem removeItem(typeQueue *queue);

#endif //FICHA1112_MYQUEUE_H
