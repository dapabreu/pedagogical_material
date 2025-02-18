#include <stdio.h>

int main()
{
    int input=-1, output = 0, i = 1;
    printf("Insira un numero inteiro:");
    scanf("%d", &input);
    if (input < 0){
        printf("O numero introduzido deve ser positivo.");
        return -1;
    }
    while (input != 0){
        output += (input % 8) * i;
        input /= 8;
        i *= 10;
    }
    printf("Output e igual a %d", output);
    return 0;
}
