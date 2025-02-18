#include <stdio.h>

int* maior(int a, int b, int c, int *ponteiro){
    if (( a > b) && (a > c)){
        ponteiro = &a;
    }
    else{
        if (b > c){
            ponteiro = &b;
        }
        else ponteiro = &c;
    }
    return ponteiro;
}

int main()
{
    int max = 0;
    int *max2 = maior(1,3,2, &max);
    printf("%d", *max2);

    return 0;
}