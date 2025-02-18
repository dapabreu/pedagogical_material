#include <stdio.h>

#define MAX 256

int main(void) {
    char s[MAX];
    
    scanf("%[^\n]", s);
    printf("1 - %s\n", s);

    scanf("%[^\n]", s);
    printf("2 - %s\n", s);

    scanf("%*[\n]%[^\n]", s);
    printf("3 - %s\n", s);

    scanf(" %[^\n]", s);
    printf("4 - %s\n", s);
}
