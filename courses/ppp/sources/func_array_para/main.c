#include <stdio.h>

int func(int v[]);

int main(){
    int vect[1];
    int j = 0;
    vect[0] = 0;
    j = func(vect);
    printf("%d %d", vect[0], j);
    return 0;
}

int func(int v[]){
    v[0] = 10;
    return v[0];
}