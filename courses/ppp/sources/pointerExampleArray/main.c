#include <stdio.h>
int main() {

    int i, x[6], sum = 0;

    printf("Enter 6 numbers:\n");
    for(i = 0; i < 6; ++i) {
        // Equivalent to scanf("%d", &x[i]);
        scanf("%d", x+i);

        // Equivalent to sum += x[i]
        sum += *(x+i);
    }
    printf("Sum = %d", sum);

    return 0;
}

/*
    Be careful with this behaviour, not always arrays names decay into pointers

    In C99 there are three fundamental cases, namely:
    - when it's the argument of the & (address-of) operator;
    - when it's the argument of the sizeof operator;
    - when it's a string literal of type char [N + 1] or a wide string literal of type wchar_t [N + 1]
    (N is the length of the string) which is used to initialize an array, as in char str[] = "foo";
    or wchar_t wstr[] = L"foo";.

    Furthermore, in C11, the newly introduced alignof operator doesn't let its array argument decay into a
    pointer either.
*/