#include <stdio.h>

int search(int, int);

int main() {
    int n, x;

    printf("Introduza o valor de n (maior do que x): ");
    scanf("%d", &n);

    printf("Introduza o valor de x (entre 1 e 99): ");
    scanf("%d", &x);

    if (search(n, x)) {
        printf("Sim, %d está contido em %d.\n", x, n);
    } else {
        printf("Não, %d não está contido em %d.\n", x, n);
    }

    return 0;
}

int search(int n, int x){
    int temp = x;
    int modulo = 1;


    while (temp != 0){
        modulo *= 10;
        temp /= 10;
    }

    while (1){
        if ((n % modulo) == x){
            return 1;
        }
        if (n < modulo){
            break;
        }
        n /= 10;
    }

    return 0;
}
