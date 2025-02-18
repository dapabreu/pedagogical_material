#include <stdio.h>
#include <stdlib.h>
#include "myStack.h"

int main() {
    size_t input_size = 0;
    char *input_line = NULL;
    pStack *myStack;
    struct item element;
    int i = 0;

    setbuf(stdout, 0);

    printf("Please introduce a string: ");

    if (getline(&input_line, &input_size, stdin) == -1) {
        free(input_line);
        //perror("Failed to read input");
        return -1;
    }

    //Creating the stack
    myStack = (noStack **) malloc(sizeof(noStack));

    //Verifying malloc
    if (myStack == NULL){
        printf("Memory not allocated on simpleQueueptr.\n");
        return -1;
    }

    while (input_line[i] != '\n'){
        element.name[0] = input_line[i];
        element.number = -1;
        push(myStack, element);
        i++;
    }

    printf("String reversed: ");

    while (!isEmpty(myStack))
        printf("%c", pop(myStack).name[0]);

    printf("\n");
    free(input_line);
    return 0;
}