#include <stdio.h>

int main() {
    int age;
    int weight;
    char name[20];

    printf("Please enter your name:");
    //scanf("%s", &name);
    scanf("%[^\n]s",  &name);
    printf("Please enter your age:");
    scanf("%d", &age);
    printf("Please enter your weight:");
    scanf("%d", &weight);

    printf("My name is %s, I am %d old and my weight is %d Kg.\n", name, age,weight);
    //printf("My name is David Abreu, I am %d old and my weight is %d Kg.\n", age,weight);

    return 0;
}
