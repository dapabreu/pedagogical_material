#include <stdio.h>
int calculaTamanho (char s[]);
int calculaTamanho2 (char *s);

int main(){
    char s[20];
    int tam;

    printf("Cadeia = ");
    scanf ("%[^\n]", s);
    tam = calculaTamanho2(s);
    printf ("Tamanho = %d\n", tam);
    return 0;
}

int calculaTamanho (char s[]){
int t = 0;
    for (int i = 0; s[i] != 0 ; i++)
        t++;
    return t;
}

int calculaTamanho2 (char *s){ // ainda não demos pointers, logo não é aconselhável para já esta solução
int t = 0;
    for (int i = 0; *(s+i) != 0 ; i++)
        t++;
    return t;
}