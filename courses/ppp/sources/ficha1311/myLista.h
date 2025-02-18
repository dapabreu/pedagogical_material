#ifndef FICHA1311_MYLISTA_H
#define FICHA1311_MYLISTA_H

struct item{
    char nome[50];
    int idade;
};

typedef struct noLista{
    struct item itemLista;
    struct noLista *prox;
} noLista;

typedef noLista *pLista;

pLista cria ();
int vazia (pLista lista);
pLista destroi (pLista lista);
void procura (pLista lista, int chave, pLista *ant, pLista *actual);
void elimina (pLista lista, int chave);
void insere (pLista lista, struct item p1);
pLista pesquisa (pLista lista, int chave);
void imprime (pLista lista);

#endif //FICHA1311_MYLISTA_H
