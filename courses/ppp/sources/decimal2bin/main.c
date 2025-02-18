#include <stdio.h>

int main() {
    setbuf(stdout, 0);
    int n, r, i;
    long long b;
    printf("Enter a positive decimal number: ");
    scanf("%d", &n);
    if (n<0){
        printf("The given number must be positive");
        return -1;
    }
    b = 0;
    i = 1;
    while (n!=0) {
        r = n % 2;
        n /= 2;
        b += r * i;
        i *= 10;
    }
    printf("Variable b is equal to %lld", b);
    return 0;
}