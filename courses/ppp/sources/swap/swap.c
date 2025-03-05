#include <stdio.h>

void swap(int *, int *);

int main(void){
    int n1 = 5;
    int n2 = 10;

    printf("Before swapping : n1 is %d and n2 is %d\n", n1, n2);
    swap(&n1, &n2);

    printf(" After swapping : n1 is %d and n2 is %d\n", n1, n2);
  
    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}