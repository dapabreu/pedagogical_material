#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include "myStack.h"
#include "myLista.h"

int main() {
    int n;
    char value[50];
    noPilha *no;
    pPilha *myPilha = &no;
    struct item element;

    setbuf(stdout, 0);

    printf("Please introduce the number of elements to add to the stack:");
    scanf("%d",&n);

    cria(myPilha);

    for(int i = 0; i<n; i++){
        printf("Element:");
        scanf("%s",value);
        strcpy(element.nome, value);
        element.numero = INT_MIN;
        push(myPilha, element);
    }

    /*
    while (!vazia(myPilha))
        printf("Output: %s\n", pop(myPilha).nome);
    */

    pLista Lista = criaL();
    struct itemL myItem;

    while (!vazia(myPilha)) {
        element = pop(myPilha);
        strcpy(myItem.nome, element.nome);
        myItem.idade = element.numero;
        insere(Lista, myItem);
    }

    imprime(Lista);

    destroiL(Lista);
    free(no);

    return 0;
}
