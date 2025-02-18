#include <stdio.h>

#define sizeArray 4

void processArray(int[]);

int main() {
    int array[sizeArray];
    //int array []= {1, 2, 3, 4};

    for (int i = 0; i < sizeArray; i++){
        printf("Introduce %d item of the array: ", i);
        scanf("%d", &array[i]);
    }

    processArray(array);
    return 0;
}
/*
void processArray(int array2[]){
    for(int j = 0; j < sizeArray; j++){
        if (j % 2 != 0)
            array2[j] *= 2;
        printf("%d \n", array2[j]);
    }
}
*/

void processArray(int array2[]){
    for(int j = 0; j < sizeArray; j++){
        if (array2[j] % 2 != 0)
            array2[j] *= 2;
        printf("%d \n", array2[j]);
    }
}
