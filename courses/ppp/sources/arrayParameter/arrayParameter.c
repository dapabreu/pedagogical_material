#include <stdio.h>

int funcao (int v[]) {
    v[0] = 10;
    return v[0];
}

int main () {
 	int vect [1];
 	int j = 0;
 	vect[0] = 0;
 	j = funcao(vect);
 	printf("%d  %d \n", vect[0], j);
 	return 0;
}
