//
// Created by david on 26/03/2023.
//

#ifndef FICHA1111V2_MYQUEUE_H
#define FICHA1111V2_MYQUEUE_H

struct myItem{
    int isNull;
    double item;
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

#endif //FICHA1111V2_MYQUEUE_H
