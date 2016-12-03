#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    printf("Введите число a (делимое): ");
    scanf("%i", &a);
    printf("Введите число b (делитель): ");
    scanf("%i", &b);

    int result = 0;
    int tempValue = b;
    while (tempValue <= a)
    {
        tempValue += b;
        result++;
    }

    printf("Неполное частное от чисел %i и %i = %i", a, b, result);

    return 0;
}