//
// Created by david on 19/04/2022.
//
#ifndef ARRAYQUEUE2_MYQUEUE_H
#define ARRAYQUEUE2_MYQUEUE_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Queue functions prototypes
struct Queue* createQueue(unsigned capacity);
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
int front(struct Queue* queue);
int rear(struct Queue* queue);

#endif //ARRAYQUEUE2_MYQUEUE_H
