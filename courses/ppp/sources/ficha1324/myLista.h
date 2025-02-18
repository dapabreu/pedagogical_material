#ifndef FICHA1324_MYLISTA_H
#define FICHA1324_MYLISTA_H

struct itemL{
    char nome[50];
    int idade;
};

typedef struct noLista{
    struct itemL itemLista;
    struct noLista *prox;
} noLista;

typedef noLista *pLista;

pLista criaL ();
int vaziaL (pLista lista);
pLista destroiL (pLista lista);
void procura (pLista lista, int chave, pLista *ant, pLista *actual);
void elimina (pLista lista, int chave);
void insere (pLista lista, struct itemL p1);
pLista pesquisa (pLista lista, int chave);
void imprime (pLista lista);

#endif //FICHA1324_MYLISTA_H
