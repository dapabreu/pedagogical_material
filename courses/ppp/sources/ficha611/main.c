#include <stdio.h>
#include <string.h>

#define sizeString 100

int main()
{
    //char string[100] = {'h', 'e','l', 'l', 'o', '\0'};
    char string[sizeString];
    int i = 0, count = 0;

    printf("Please, introduce a string: ");
    //scanf("%s", string);
    //gets(string);
    fgets(string, sizeString, stdin);
    //Counts each character except space
    while (string[i] != '\0'){
        i++;
        count++;
        /*if (string[i] != ' ')
            count++;*/
    }
    printf("Total number of characters: %d\n", count);
    printf("Total number of characters (strlen): %zu\n", strlen(string));

    return 0;
}