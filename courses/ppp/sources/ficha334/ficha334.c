#include <stdio.h>

int prime(int);

int main() {
    int n;
    printf("Introduce a number: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++){
        if (prime(i))
            printf("%d ", i);
    }
    return 0;
}

int prime(int p){
    int flag = 0;
    for (int i = 2; i <= p; i++){
        if (p%i==0)
            flag++;
        if (flag > 1)
            return 0;
    }
    return 1;
}
