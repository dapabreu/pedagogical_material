//
// Created by david on 25/04/2022.
//

#ifndef FICHA1131_MYQUEUE_H
#define FICHA1131_MYQUEUE_H

struct myItem{
    int isNull;
    int item;
    int amount;
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


#endif //FICHA1131_MYQUEUE_H
