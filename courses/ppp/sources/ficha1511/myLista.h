#ifndef FICHA1511_MYLISTA_H
#define FICHA1511_MYLISTA_H

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
void procura (pLista lista, char chave [], pLista *ant, pLista *actual);
void elimina (pLista lista, char chave []);
void insere (pLista lista, struct item p1);
pLista pesquisa (pLista lista, char chave []);
void imprime (pLista lista);

#endif //FICHA1511_MYLISTA_H
