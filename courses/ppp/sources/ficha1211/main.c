#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#include "myStack.h"

int main() {
    int n;
    char value[50];
    pStack *myStack;
    struct item element;

    setbuf(stdout, 0);

    printf("Please introduce the number of elements to add to the stack: ");
    scanf("%d",&n);

    //Creating the queue
    myStack = (noStack **) malloc(sizeof(noStack));

    //Verifying malloc
    if (myStack == NULL){
        printf("Memory not allocated on simpleQueueptr.\n");
        return -1;
    }

    create(myStack);

    for(int i = 0; i<n; i++){
        printf("Element: ");
        scanf("%s",value);
        strcpy(element.name, value);
        element.number = INT_MIN;
        push(myStack, element);
    }

    while (!isEmpty(myStack))
        printf("Output: %s\n", pop(myStack).name);

    destroy(myStack);
    free(myStack);

    return 0;
}
