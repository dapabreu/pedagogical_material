#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "myLista.h"

int main() {
    int n, age;
    char name[50];
    pLista Lista = cria();
    struct item myItem;

    //setbuf(stdout, 0);

    printf("# of elements to add to the list: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Add a name: ");
        scanf("%s", name);
        strcpy(myItem.nome, name);
        printf("Add an age: ");
        scanf("%d", &age);
        myItem.idade = age;
        insere(Lista, myItem);
    }

    printf("--- This is the list ---\n");

    imprime(Lista);

    printf("--- Keeping the list in a file ---\n");

    FILE *fptr;

    if ((fptr = fopen("..\\program.bin","wb")) == NULL){
        printf("Error opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    //Iterating the List to save the structs with the data
    pLista auxLista = Lista->prox;

    while (auxLista) {
        myItem = auxLista->itemLista;
        fwrite(&myItem, sizeof(struct item), 1, fptr);
        auxLista = auxLista->prox;
    }

    //Free the first list
    destroi(Lista);
    fclose(fptr);

    printf("--- Recovering the list using the file ---\n");

    pLista Lista2 = cria();

    if ((fptr = fopen("..\\program.bin","r")) == NULL){
        printf("Error opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    for(int i = 0;  i < n; i++){
        fread(&myItem, sizeof(struct item), 1, fptr);
        insere(Lista2, myItem);
    }

    imprime(Lista2);

    printf("--- Done! ---\n");

    //Free the second list
    destroi(Lista2);
    fclose(fptr);

    return 0;
}
