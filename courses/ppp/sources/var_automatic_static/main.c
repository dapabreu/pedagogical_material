#include <stdio.h>
void count(int);

int main(void)
{
    // auto int i; == int i;
    auto int i;    /* 'i' declared automatic */

    for (i = 1; i <= 5; i++)
        count(i);

    return 0;
}

void count(int iteration)
{
    //int j;
    static int j;
    printf("Value of \"static int j\" in count(%d) is %d\n", iteration, ++j);
}