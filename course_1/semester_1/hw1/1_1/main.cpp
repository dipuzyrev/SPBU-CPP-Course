#include <stdio.h>

int main()
{
    printf("Выражение: x^4 + x^3 + x^2 + x + 1\n");
    printf("Введите x: ");
    double x = 0.0;
    scanf("%f", &x);

    // x^4 + x^3 + x^2 + x + 1 = (x^2 + x)(x^2 + 1) + 1
    double xInPow = x * x;
    double expressionValue = (xInPow + x) * (xInPow + 1) + 1;

    printf("Вычисленное значение: %f", expressionValue);

    return 0;
}