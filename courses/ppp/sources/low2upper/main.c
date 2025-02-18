#include<stdio.h>

int main()
{
    char s[100];
    int i = 0;

    printf("Enter a string:");
    scanf("%[^\n]", s);

    // iterate loop until the end of the string
    while( s[i] != '\0' )
    {
        // if character is in lowercase then subtract 32 low2upper
        if( s[i] >= 'a' && s[i] <= 'z' ){
            s[i] = s[i] - 32;
        }
        else{
            // if character is in uppercase then add 32 upper2low
            if( s[i] >= 'A' && s[i] <= 'Z' )
            {
                s[i] = s[i] + 32;
            }
        }
        // increase iterator variable
        i++;
    }

    // display result
    printf("The output is: ");
    puts(s);

    return 0;
}