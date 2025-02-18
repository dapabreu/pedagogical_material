#include <stdio.h>

int search(int, int);

int main(){
    int n, x;

    printf("Introduce the first number (big number):");
    scanf("%d", &n);
    printf("Introduce the second number (part of):");
    scanf("%d", &x);
    //printf("x= %d and n= %d --> %d", x, n, search(n,x));
    for(int i = x; i < n; i++){
        if (search(i, x))
            printf("%d is in %d\n", x, i);
    }
    return 0;
}

int search (int n, int x){
    int modulo=1;
    int len= x;

    do{
        modulo *= 10;
    }while ((len/=10) != 0);


    for (;;){
        if ((n%modulo) == x)
            return 1;
        if (n<modulo)
            break;
        n/= 10;
    }
    return 0;
}