#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[200];
    char lLine[200];
    int charRead, j;
    int aux = -1;
    FILE *fptr;

    if ((fptr = fopen("..\\data.txt","r")) == NULL){
        printf("Error opening file!");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    charRead = fscanf(fptr, "%s", line);
    //charRead = fscanf(fptr, "%[^\n\r]s", line);

    while(charRead != EOF){
        j = 0;
        while(line[j] != '\0'){
            j++;
        }

         if(j > aux){
             aux = j;
             strcpy(lLine, line);
         }
        charRead = fscanf(fptr, "%s", line);
    }

    fclose(fptr);
    printf("The longest lines in the file is --> %s \n", lLine);

    return 0;
}