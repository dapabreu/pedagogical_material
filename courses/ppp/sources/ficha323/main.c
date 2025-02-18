#include <stdio.h>

int main() {
    int num, sum, dig;
    printf("Please, introduce a number: ");
    scanf("%d", &num);
    sum = 0;
    do{
        dig = num % 10;
        num = num / 10;
        sum = sum + dig;
    }while(num);
    printf("The sum of the digits is %d\n", sum);
    return 0;
}
