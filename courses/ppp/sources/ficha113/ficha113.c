#include <stdio.h>
#include <math.h>

int main() {
    float r;
    float h;
    float v;


    printf("Please enter the radio:");
    scanf("%f", &r);
    printf("Please enter the height:");
    scanf("%f", &h);

    v = 2*M_PI*r*(r+h);

    printf("The volume is %f \n", v);

    return 0;
}
