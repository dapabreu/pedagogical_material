#define N_DECIMAL_POINTS_PRECISION (1000) // n = 3. Three decimal points.

int main() {
    //float f = 123.456;
    float f;
    scanf("%f", &f);
    int integerPart = (int) f;
    int decimalPart = ((int) (f * N_DECIMAL_POINTS_PRECISION) % N_DECIMAL_POINTS_PRECISION);
    printf("%d\n", integerPart);
    printf("%d\n", decimalPart);
}