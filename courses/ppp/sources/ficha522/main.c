#include <stdio.h>

void somavetores(int a, double v1[], double v2[], double vres[]){
    for(int i=0;i<a;i++){
        vres[i]=v1[i]+v2[i];
    }
}

int main(){
    int i = 0;
    double v1[5];
    double v2[5];
    double vres[5];

    for(int j=0;j<5;j++){
        printf("v1[%d]=",j);
        scanf("%lf", &v1[j]);
    }
    for(int j=0;j<5;j++){
        printf("v2[%d]=",j);
        scanf("%lf", &v2[j]);
    }
    somavetores(5,v1,v2,vres);
    while (i<5){
        printf("%lf \n",vres[i]);
        i++;
    }
}