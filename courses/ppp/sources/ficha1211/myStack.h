//
// Created by david on 28/04/2022.
//

#ifndef STACKPT_MYSTACK_H
#define STACKPT_MYSTACK_H

struct item{
    char name[50];
    int number;
};

typedef struct noStack{
    struct item itemStack;
    struct noStack *prox;
} noStack;

typedef noStack *pStack;

void create(pStack *stack);
int isEmpty(pStack *stack);
void destroy(pStack *stack);
void push(pStack *stack, struct item p1);
struct item pop(pStack *stack);
struct item peek(pStack *stack);

#endif //STACKPT_MYSTACK_H
