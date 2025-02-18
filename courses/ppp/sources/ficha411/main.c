#include <stdio.h>

unsigned long long factorial (int n);

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);
    if (n < 0)
        printf("Error! Factorial of a negative number doesn't exist\n");
    else
        printf("The factorial of %d is %llu\n", n, factorial(n));
    return 0;
}

unsigned long long factorial (int n){
    int i;
    unsigned long long fact = 1;

    if (n == 0)
        return 1;
    else{
        for (i = 1; i <= n; ++i){
            fact *= i;
        }
        return fact;
    }
}
