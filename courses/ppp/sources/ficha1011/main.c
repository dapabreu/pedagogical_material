#include <stdio.h>
#include <stdlib.h>

void readElements(int* ptrArray, int size);
void minmaxArray(int *ptrArray, int *min, int *max, int size);

int main()
{
    // This pointer will hold the base address of the block created
    int *ptrArray, *min, *max;
    int a,b,n;
    a = 1000000;
    b = -1;
    min = &a;
    max = &b;

    // Get the number of elements for the array
    printf("Enter number of elements: ");
    scanf("%d",&n);

    // Dynamically allocate memory using malloc()
    ptrArray = (int*) malloc(n * sizeof(int));

    // Check if the memory has been successfully allocated by malloc or not
    if (ptrArray == NULL){
        printf("Memory not allocated.\n");
        exit(1);
    }
    else{
        //readElements
        printf("Memory successfully allocated using malloc.\n");
        readElements(ptrArray, n);
    }
    //MinMax
    minmaxArray(ptrArray, min, max, n);
    printf("The Min and Max values in the array are: %d and %d\n",*min,*max);
    free(ptrArray);
    return 0;
}

void readElements(int* ptrArray, int size){
    for(int i=0; i<size; i++){
        printf("Introduce the %d array element: ", i);
        scanf("%d",&ptrArray[i]);
    }
}

void minmaxArray(int *ptrArray, int *min, int *max, int size){
    for (int i=0; i<size; i++){
        if (ptrArray[i]<*min)
            *min = ptrArray[i];
        if (ptrArray[i]>*max)
            *max = ptrArray[i];
    }
}