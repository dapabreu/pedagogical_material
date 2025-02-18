#include <stdio.h>

int main(){
    int int_number;
    printf("Please introduce an integer number:");
    scanf("%d", &int_number);

    if (int_number % 2 == 0)
        printf("The number %d is even\n", int_number);
    else
        printf("The number %d is odd\n", int_number);
    return 0;
}
