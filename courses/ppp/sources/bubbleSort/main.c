#include <stdio.h>

//Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

/*

 Sorts algorithms:
 - Selection Sort
    + Two subarrays (i.e., sorted, unsorted)
    + In every iteration of selection sort, the minimum element from the unsorted subarray is picked and moved to
    the sorted subarray.
 - Bubble Sort
    + This implementation
 - Merge Sort
    + MergeSort(arr[], l,  r)
        If r > l
             1. Find the middle point to divide the array into two halves:
                     middle m = l+ (r-l)/2
             2. Call mergeSort for first half:
                     Call mergeSort(arr, l, m)
             3. Call mergeSort for second half:
                     Call mergeSort(arr, m+1, r)
             4. Merge the two halves sorted in step 2 and 3:
                     Call merge(arr, l, m, r)
 - Radix Sort
    + Homework
 - Insertion Sort
    + Homework
*/
