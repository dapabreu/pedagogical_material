#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myStack.h"

int main() {
    int n, value;
    pStack *myStack;
    struct item element;

    setbuf(stdout, 0);

    printf("Please introduce the number of elements to add to the stack: ");
    scanf("%d",&n);

    //Creating the stack
    myStack = (noStack **) malloc(sizeof(noStack));

    //Verifying malloc
    if (myStack == NULL){
        printf("Memory not allocated on simpleQueueptr.\n");
        return -1;
    }

    create(myStack);

    for(int i = 0; i<n; i++){
        printf("Element: ");
        scanf("%d",&value);
        strcpy(element.name, "");
        element.number = value;
        push(myStack, element);
    }

    while (!isEmpty(myStack))
        printf("Output: %d\n", pop(myStack).number);

    //destroy(myPilha);
    free(myStack);
    return 0;
}
