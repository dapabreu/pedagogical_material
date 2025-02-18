#include <stdio.h>
#include <string.h>

#include "myLista.h"

int main() {
    int n;
    char element[50];
    pLista Lista = cria();
    pLista Lista2 = cria();
    struct item myItem;

    setbuf(stdout, 0);

    printf("# of elements in the first list: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Element: ");
        scanf("%s", element);
        strcpy(myItem.myString, element);
        myItem.num = -1;
        insere(Lista, myItem);
    }

    imprime(Lista);

    printf("# of elements in the second list: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Element: ");
        scanf("%s", element);
        strcpy(myItem.myString, element);
        myItem.num = -1;
        insere(Lista2, myItem);
    }

    imprime(Lista2);

    concatenaLista(Lista, Lista2);

    destroi(Lista2);

    printf("----------\n");

    printf("Lists merged\n");

    imprime(Lista);

    destroi(Lista);

    return 0;
}