//
// Created by david on 28/04/2022.
//

#ifndef STACKPT_MYSTACK_H
#define STACKPT_MYSTACK_H

struct pessoa {
    char nome[50];
    int idade;
};

typedef struct noPilha {
    struct pessoa pessoaPilha;
    struct noPilha * prox;
} noPilha;

typedef noPilha * pPilha;

void cria (pPilha * pilha);
int vazia (pPilha *pilha);
void destroi (pPilha *pilha);
void push (pPilha *pilha, struct pessoa p1);
struct pessoa pop (pPilha *pilha);

#endif //STACKPT_MYSTACK_H
