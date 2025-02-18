#include <stdio.h>

#define max 12

double vectorAverage (int v[], int n) {
    double sum = 0.0;
    int *ptr;
    int *endptr = v + (n-1);

    for (ptr = v; ptr <= endptr; ptr++)
        sum += *ptr;

    if (n != 0) return sum / n;
    else return 0.0;
}

int main() {
    int array[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    printf("AVG = %lf", vectorAverage(array, max));
    return 0;
}
