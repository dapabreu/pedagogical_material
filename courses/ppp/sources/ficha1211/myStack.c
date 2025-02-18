//
// Created by david on 28/04/2022.
//
#include <stdlib.h>
#include <stdio.h>
#include "myStack.h"

void create(pStack *stack){
    *stack = NULL;
}

int isEmpty(pStack *stack){
    if (*stack == NULL)
        return 1;
    else
        return 0;
}

void destroy(pStack *stack){
    pStack temp_ptr;
    while (!isEmpty(stack)){
        temp_ptr = *stack;
        *stack = temp_ptr->prox;
        free (temp_ptr);
    }
}

void push(pStack *stack, struct item p1){
    pStack temp_ptr;
    temp_ptr = (pStack) malloc (sizeof (noStack));
    if (temp_ptr != NULL){
        temp_ptr->itemStack = p1;
        temp_ptr->prox = *stack;
        *stack = temp_ptr;
    }
}

struct item pop(pStack *stack){
    pStack temp_ptr;
    struct item p1 = {"", -1};
    if (!isEmpty(stack)) {
        temp_ptr = *stack;
        p1 = (*stack)->itemStack;
        *stack = temp_ptr->prox;
        free (temp_ptr);
    }
    return (p1);
}

struct item peek(pStack *stack){
    struct item p1 = {"", -1};
    if(!isEmpty(stack)){
        return((*stack)->itemStack);
    }
    else
        return(p1);
}