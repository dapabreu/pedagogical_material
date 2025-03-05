#include <stdio.h>

void calChecksum(int [], int, int);
void calChecksum2(int [], int, int);

int main(){
    int data[] = {10, 20, 30, 40, 0}; // 0 will be replaced by the CRC value
    int size = sizeof(data) / sizeof(data[0]);
    int mod = 256; // Our modulo value

    calChecksum(data, size, mod);

    printf("Message with Checksum: ");
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");

    return 0;
}

void calChecksum(int arr[], int size, int mod){
    int sum = 0; 
    for (int i = 0; i < size - 1; i++)
        sum += arr[i];

    arr[size - 1] = sum % mod;
}


void calChecksum2(int arr[], int size, int modulo) {
    int sum = 0;
    int *ptr;

    for (ptr = arr; ptr < arr + size - 1; ptr++) {
        sum += *ptr;
    }

    *(arr + size - 1) = sum % modulo;
}
