#include <stdio.h>

#include "myStack.h"

int main(){
    struct node *top = NULL;

    printf("isEmpty = %d\n", isEmpty(top));

    printf("Adding elements!\n");

    top=push(top,5);
    top=push(top,6);
    top=push(top,7);
    top=push(top,8);
    top=push(top,9);

    printf("isEmpty = %d\n", isEmpty(top));

    printf("Removing elements!\n");

    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);

    printf("isEmpty = %d\n", isEmpty(top));

    return 0;
}
