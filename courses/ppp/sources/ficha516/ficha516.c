#include <stdio.h>

#define rows 4
#define columns 4

void printMatrix(int[rows][columns]);

int main() {
    int matrix[][columns] = {{0, 1, 2, 3},
                             {4, 5, 6, 7},
                             {8, 9, 10, 11},
                             {12, 13, 14, 15}};

    printMatrix(matrix);
    return 0;
}

void printMatrix(int matrix2[rows][rows])
{
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < columns; j++) {
            printf("%d", matrix2[i][j]);
            if (j < columns - 1)
                printf(",");
            else
                printf("\n");
        }
    }
}
