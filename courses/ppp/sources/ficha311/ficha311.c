#include <stdio.h>

int main(){
    int i, hnumber, sum;
    
    printf("Please, introduce the higher of the numbers to be added: ");
    scanf("%d",&hnumber);
    
    i= 1;
    sum= 0;
    while(i<=hnumber){
        sum = sum + i;
        i++;
        //i = i + 1;
    }
    printf("The sum from 1 to %d is: %d\n", hnumber, sum);
    return 0;
}
