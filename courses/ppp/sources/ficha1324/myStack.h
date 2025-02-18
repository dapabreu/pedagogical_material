#ifndef FICHA1324_MYSTACK_H
#define FICHA1324_MYSTACK_H

struct item{
    char nome[50];
    int numero;
};

typedef struct noPilha {
    struct item pessoaPilha;
    struct noPilha * prox;
} noPilha;

typedef noPilha * pPilha;

void cria (pPilha * pilha);
int vazia (pPilha *pilha);
void destroi (pPilha *pilha);
void push (pPilha *pilha, struct item p1);
struct item pop (pPilha *pilha);

#endif //FICHA1324_MYSTACK_H
