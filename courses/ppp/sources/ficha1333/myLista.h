//
// Created by david on 01/05/2023.
//

#ifndef FICHA1333_MYLISTA_H
#define FICHA1333_MYLISTA_H

struct item{
    int numero;
    char nome[50];
    char dataNacimento[11];
    int pontuacao;
};

typedef struct noLista{
    struct item itemLista;
    struct noLista *prox;
} noLista;

typedef noLista *pLista;

typedef struct noListaAux{
    struct noLista *pListaOrig;
    struct noListaAux *proxAux;
}noListaAux;

typedef noListaAux *pListaAux;

pLista cria ();
int vazia (pLista lista);
pLista destroi (pLista lista);
void procura (pLista lista, int chave, pLista *ant, pLista *actual);
void elimina (pLista lista, int chave);
void insere (pLista lista, struct item p1);
void insereNoDuplicado (pLista lista, struct item p1);
pLista pesquisa (pLista lista, int chave);
void imprime (pLista lista);
void concatenaLista(pLista lista, pLista lista2);

pListaAux criaAux ();
int vaziaAux (pListaAux lista);
pListaAux destroiAux (pListaAux lista);
pListaAux org2aux (pLista listaOrg, pListaAux listaAux);
void imprimeAux (pListaAux lista);
void bubbleSortList(pListaAux listaAux, int key);
void swapAuxList(pListaAux a, pListaAux b);


#endif //FICHA1333_MYLISTA_H
