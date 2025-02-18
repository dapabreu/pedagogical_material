#include<stdio.h>
#include<math.h>

int main()
{
    //float degree, radian;
    float degree, minutes, seconds, radian;

    //printf("Enter angle in Degrees:");
    printf("Enter Degrees:");
    scanf("%f", &degree);
    printf("Enter Minutes:");
    scanf("%f", &minutes);
    printf("Enter Seconds:");
    scanf("%f", &seconds);

    //radian = degree*(M_PI/180.0);
    radian= M_PI * ((degree+(minutes/60)+(seconds/3600))/180);

    printf("Angle in Radian is %f\n", radian);

    return 0;
}