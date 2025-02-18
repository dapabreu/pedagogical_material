#include <stdio.h>
#include <math.h>

int main(){
    double a, b, hypotenuse;
    //double hypotenuse;

    //a = 5.0;
    //b = 12.0;

    printf("Introduce the value of a: ");
    scanf("%lf", &a);
    printf("Introduce the value of b: ");
    scanf("%lf", &b);

    hypotenuse = sqrt(pow(a, 2) + pow(b, 2));
    //hypotenuse = sqrt((a * a) + (b * b));

    printf("hypot(%.2lf, %.2lf) = %.2lf\n", a, b, hypotenuse);

    return 0;
}
