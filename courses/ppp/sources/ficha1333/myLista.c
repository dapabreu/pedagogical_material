//
// Created by david on 01/05/2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myLista.h"

pLista cria (){
    pLista aux;
    struct item p1 = {0,"","", 0};
    aux = (pLista) malloc (sizeof (noLista));
    if (aux != NULL){
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

void procura (pLista lista, int chave, pLista *ant, pLista *actual){
    *ant = lista; *actual = lista->prox;
    while ((*actual) != NULL && ((*actual)->itemLista.numero < chave)){
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && ((*actual)->itemLista.numero < chave))
        *actual = NULL;
}

void elimina (pLista lista, int chave){
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
        procura (lista, p1.numero, &ant, &inutil);
        no->prox = ant->prox;
        ant->prox = no;
    }
}

void insereNoDuplicado (pLista lista, struct item p1){
    pLista no, ant, inutil;
    no = (pLista) malloc (sizeof (noLista));
    if (no != NULL){
        no->itemLista = p1;
        procura (lista, p1.numero, &ant, &inutil);
        if (strcmp(ant->prox->itemLista.nome, p1.nome) != 0) {
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
}

pLista pesquisa (pLista lista, int chave){
    pLista ant, actual;
    procura (lista, chave, &ant, &actual);
    return (actual);
}

void imprime (pLista lista){
    pLista aux = lista->prox; /* Salta o header */
    while (aux){
        printf("%d -- %s -- %s -- %d\n", aux->itemLista.numero, aux->itemLista.nome, aux->itemLista.dataNacimento, aux->itemLista.pontuacao);
        aux = aux->prox;
    }
}

void concatenaLista(pLista lista, pLista lista2){
    pLista aux = lista2->prox;
    while (aux){
        insereNoDuplicado(lista, aux->itemLista);
        aux = aux->prox;
    }
}

pListaAux criaAux (){
    pListaAux aux = NULL;
    return aux;
}

int vaziaAux (pListaAux lista){
    if (lista == NULL)
        return 1;
    else
        return 0;
}

pListaAux destroiAux (pListaAux lista){
    pListaAux temp_ptr;
    while (!vaziaAux(lista)) {
        temp_ptr = lista;
        lista = lista->proxAux;
        free (temp_ptr);
    }
    free(lista);
    return NULL;
}

pListaAux org2aux (pLista listaOrg, pListaAux listaAux){
    if (vazia(listaOrg))
        return NULL;
    else{
        pLista pauxLista;
        pListaAux pauxListaAux;
        pListaAux pauxListaAux2;
        pauxLista = listaOrg->prox;
        while (pauxLista){
            pauxListaAux = (pListaAux) malloc(sizeof (noListaAux));
            pauxListaAux->pListaOrig = pauxLista;
            if (vaziaAux(listaAux))
                listaAux = pauxListaAux;
            else
                pauxListaAux2->proxAux = pauxListaAux;
            pauxListaAux->proxAux = NULL;
            pauxListaAux2 = pauxListaAux;
            pauxLista = pauxLista->prox;
        }
        return listaAux;
    }
}

void bubbleSortList(pListaAux listaAux, int key){
    int swapped;
    pListaAux actPtr;
    pListaAux prevPtr = NULL;

    if (vaziaAux(listaAux))
        return;

    switch (key) {
        case 1:
            /*
            do{
                swapped = 0;
                actPtr = listaAux;

                while (actPtr->proxAux != prevPtr){
                    if (actPtr->pListaOrig->itemLista.numero > actPtr->proxAux->pListaOrig->itemLista.numero){
                        swapAuxList(actPtr, actPtr->proxAux);
                        swapped = 1;
                    }
                    actPtr = actPtr->proxAux;
                }
                prevPtr = actPtr;
            } while (swapped);
            */
            break;
        case 2:
            do{
                swapped = 0;
                actPtr = listaAux;

                while (actPtr->proxAux != prevPtr){
                    if (strcmp(actPtr->pListaOrig->itemLista.nome, actPtr->proxAux->pListaOrig->itemLista.nome) > 0){
                        swapAuxList(actPtr, actPtr->proxAux);
                        swapped = 1;
                    }
                    actPtr = actPtr->proxAux;
                }
                prevPtr = actPtr;
            } while (swapped);
            break;
        case 3:
            do{
                swapped = 0;
                actPtr = listaAux;

                while (actPtr->proxAux != prevPtr){
                    if (strcmp(actPtr->pListaOrig->itemLista.dataNacimento, actPtr->proxAux->pListaOrig->itemLista.dataNacimento) > 0){
                        swapAuxList(actPtr, actPtr->proxAux);
                        swapped = 1;
                    }
                    actPtr = actPtr->proxAux;
                }
                prevPtr = actPtr;
            } while (swapped);
            break;
        case 4:
            do{
                swapped = 0;
                actPtr = listaAux;

                while (actPtr->proxAux != prevPtr){
                    if (actPtr->pListaOrig->itemLista.pontuacao > actPtr->proxAux->pListaOrig->itemLista.pontuacao){
                        swapAuxList(actPtr, actPtr->proxAux);
                        swapped = 1;
                    }
                    actPtr = actPtr->proxAux;
                }
                prevPtr = actPtr;
            } while (swapped);
            break;
        default:
            printf("Wrong option in the bubbleSortList key %d. \n", key);
            exit(0);
    }
}

void swapAuxList(pListaAux a, pListaAux b){
    pLista temp = a->pListaOrig;
    a->pListaOrig = b->pListaOrig;
    b->pListaOrig = temp;
}

void imprimeAux (pListaAux lista){
    pListaAux aux = lista; /* Salta o header */
    while (aux){
        printf("#: %d -- Nome: %s -- Data: %s -- Pontos: %d\n", aux->pListaOrig->itemLista.numero, aux->pListaOrig->itemLista.nome, aux->pListaOrig->itemLista.dataNacimento, aux->pListaOrig->itemLista.pontuacao);
        aux = aux->proxAux;
    }
}
