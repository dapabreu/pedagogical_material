#ifndef FICHA1325_MYLISTA_H
#define FICHA1325_MYLISTA_H

struct item{
    char myString[50];
    int num;
};

typedef struct noLista{
    struct item itemLista;
    struct noLista *prox;
} noLista;

typedef noLista *pLista;

pLista cria ();
int vazia (pLista lista);
pLista destroi (pLista lista);
void procura (pLista lista, char chave [], pLista *ant, pLista *actual);
void elimina (pLista lista, char chave []);
void insere (pLista lista, struct item p1);
void insereNoDuplicado (pLista lista, struct item p1);
pLista pesquisa (pLista lista, char chave []);
void imprime (pLista lista);
void concatenaLista(pLista lista, pLista lista2);

#endif //FICHA1325_MYLISTA_H
