#include <stdio.h>

#define sizeMax 50
#define sizeCoding 26

int main (){
    char linha1[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char linha2[] = {'D','E','I','A','B','C','F','G','H','J','K','L','Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M'};
    char s[sizeMax],codificado[sizeMax];
    
    printf ("Introduza uma frase para codificar: ");
    fgets(s, sizeMax, stdin);

    for (int i = 0; i < sizeMax; i++){
        //Check if s[i] is the last char in the string
        if ((s[i] == '\n') || (s[i] == '\0')){
            //NULL is assigned to codificado
            codificado[i] = '\0';
            break; //Interrupt the for given there are no more chars to process
        }
        for (int j = 0; j < sizeCoding; j++){
            if(s[i] == linha1[j]){
                codificado[i] = linha2[j];
                break; //Interrupt the for given a match was detected
            }
            //There are no match --> keep the same char
            if(j == 25)
                codificado[i] = s[i];        
        }
    }
    
    printf ("\n");
    printf ("String normal: %s\n", s);
    printf("String Codificada: %s\n", codificado);
    return 0;
}
