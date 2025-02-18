#include <stdio.h>
#include <string.h>

#include "myLista.h"

int main() {
    int n, element;
    pLista Lista = cria();
    struct item myItem;

    //Print during debugging in CLion
    //setbuf(stdout, 0);

    printf("# of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Element: ");
        scanf("%d", &element);
        strcpy(myItem.nome, "");
        myItem.idade = element;
        insere(Lista, myItem);
    }

    imprime(Lista);
    destroi(Lista);

    return 0;
}
