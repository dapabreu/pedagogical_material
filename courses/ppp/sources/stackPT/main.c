#include <stdio.h>

#include "myStack.h"

int main() {
    noPilha *no;
    pPilha *myPilha = &no;
    struct pessoa p = {"David", 39};

    cria(myPilha);
    push(myPilha, p);
    p = pop(myPilha);
    printf("Value %s", p.nome);

    return 0;
}
