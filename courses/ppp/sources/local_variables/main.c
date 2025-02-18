#include <stdio.h>

//void func(int i);

/*void func(int i){
    i = 3;
    printf("i inside %d\n", i);
}*/

int main() {
    /*
    int i = 1;
    printf("i before %d\n", i);
    func(i);
    printf("i after %d\n", i);
    
    */
    int j = -1;
    //printf("j before for %d\n", j);
    for (int j = 0; j <= 3;){
        printf("j inside the for %d\n", j);
        j++;
    }
    printf("j after for %d\n", j);
    
    return 0;
}
/*
void func(int i){
    i= 3;
    printf("i inside %d\n", i);
}*/
