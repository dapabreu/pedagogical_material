//
// Created by david on 28/04/2022.
//

#ifndef STACKIMP_MYSTACK_H
#define STACKIMP_MYSTACK_H

struct node{
    int data;
    struct node * next;
};

int isEmpty(struct node *top);
struct node *push(struct node *top,int data);
struct node *pop(struct node *top);
void peek(struct node *top);
void view_stack(struct node *top);

#endif //STACKIMP_MYSTACK_H
