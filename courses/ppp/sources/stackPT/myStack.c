//
// Created by david on 28/04/2022.
//
#include <stdlib.h>
#include <stdio.h>

#include "myStack.h"

void cria (pPilha * pilha){
    *pilha = NULL;
}

int vazia (pPilha *pilha){
    if (*pilha == NULL)
        return 1;
    else
        return 0;
}

void destroi (pPilha *pilha){
    pPilha temp_ptr;
    while (!vazia(pilha)) {
        temp_ptr = *pilha;
        *pilha = temp_ptr->prox;
        free (temp_ptr);
    }
}

void push (pPilha *pilha, struct pessoa p1){
    pPilha temp_ptr;
    temp_ptr = (pPilha) malloc (sizeof (noPilha));
    if (temp_ptr != NULL) {
        temp_ptr->pessoaPilha = p1;
        temp_ptr->prox = *pilha;
        *pilha = temp_ptr;
    }
}

struct pessoa pop (pPilha *pilha){
    pPilha temp_ptr;
    struct pessoa p1 = {"", 0};
    if (!vazia(pilha)) {
        temp_ptr = *pilha;
        p1 = (*pilha)->pessoaPilha;
        *pilha = temp_ptr->prox;
        free (temp_ptr);
    }
    return (p1);
}
