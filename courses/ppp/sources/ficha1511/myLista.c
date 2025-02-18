#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myLista.h"

pLista cria (){
    pLista aux;
    struct item p1 = {"", 0};
    aux = (pLista) malloc (sizeof (noLista));
    if (aux != NULL) {
        aux->itemLista = p1;
        aux->prox = NULL;
    }
    return aux;
}

int vazia (pLista lista){
    if (lista->prox == NULL)
        return 1;
    else
        return 0;
}

pLista destroi (pLista lista){
    pLista temp_ptr;
    while (!vazia (lista)) {
        temp_ptr = lista;
        lista = lista->prox;
        free (temp_ptr);
    }
    free(lista);
    return NULL;
}

void procura (pLista lista, char chave [], pLista *ant, pLista *actual){
    *ant = lista; *actual = lista->prox;
    while ((*actual) != NULL && (strcmp((*actual)->itemLista.nome, chave) < 0)){
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && (strcmp((*actual)->itemLista.nome, chave) == 0))
        *actual = NULL;
}

void elimina (pLista lista, char chave []){
    pLista ant, actual;
    procura (lista, chave, &ant, &actual);
    if (actual != NULL) {
        ant->prox = actual->prox;
        free (actual);
    }
}

void insere (pLista lista, struct item p1){
    pLista no, ant, inutil;
    no = (pLista) malloc (sizeof (noLista));
    if (no != NULL){
        no->itemLista = p1;
        procura (lista, p1.nome, &ant, &inutil);
        no->prox = ant->prox;
        ant->prox = no;
    }
}

pLista pesquisa (pLista lista, char chave []){
    pLista ant, actual;
    procura (lista, chave, &ant, &actual);
    return (actual);
}

void imprime (pLista lista){
    pLista aux = lista->prox; /* Salta o header */
    while (aux){
        printf("%s %d\n", aux->itemLista.nome, aux->itemLista.idade);
        aux = aux->prox;
    }
}
