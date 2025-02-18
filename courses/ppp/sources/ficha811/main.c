#include <stdio.h>
/*
int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(1){
        celsius = (5.0/9.0) * (fahr-32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
        if (fahr > upper) break;
    }
    return 0;
}*/


int main(){
    float *fahr, celsius;
    float *celsiusp;
    int lower, upper, step;
    int *stepp, *upperp;

    lower = 0;
    upper = 300;
    upperp = &upper;
    step = 20;
    stepp = &step;

    fahr = (float *)&lower;
    celsiusp = &celsius;
    while(1){
        *celsiusp = (5.0/9.0) * (*fahr-32);
        printf("%3.0f %6.1f\n", *fahr, *celsiusp);
        *fahr += *stepp;
        if (*fahr > *upperp) break;
    }
    return 0;
}
