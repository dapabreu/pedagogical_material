//
// Created by david on 28/04/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "myStack.h"

int isEmpty(struct node *top){
    return top == NULL ? 1 : 0;
}

struct node *push(struct node *top, int data){
    struct node * temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=top;
    top=temp;
    printf("%d is pushed\n",top->data);
    view_stack(top);
    return top;
}

struct node *pop(struct node *top){
    struct node * temp;
    temp=top;
    if(top==NULL){
        printf("Stack Empty!Nothing To Pop\n");
        return NULL;
    }

    top=top->next;
    printf("%d is popped\n",temp->data);
    free(temp);
    view_stack(top);
    return top;
}

void peek(struct node *top){
    if(top==NULL)
        printf("Stack Empty\n");
    else
        printf("Top Item=%d",top->data);
}

void view_stack(struct node *top){
    struct node* temp=top;
    printf("Your Current Stack:\n");
    printf("\n");
    while(temp!=NULL){
        printf("-------\n|  %d  |\n-------\n",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
