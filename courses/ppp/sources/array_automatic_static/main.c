#include <stdio.h>

void update(int);

int main(void)
{
    update(1);
    update(0);
    return 0;
}

void update(int FLAG)
{
    //int count[10] = {12, 34, 45, 123, 1, 3, 56, 90, 88, 100};
    static int count[10] = {12, 34, 45, 123, 1, 3, 56, 90, 88, 100};
    int i;

    if (FLAG) {
        for(i = 0; i < 10; i++)
            count[i] += 5;
        printf("Updated data!\n");
    }
    else {
        printf("No need!\n");
    }
}
