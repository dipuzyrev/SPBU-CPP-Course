#include <stdio.h>

int getPow(int x, int y)
{
    int result = x;
    for (int i = y; i > 1; i--)
    {
        result *= result;
    }
    return result;
}

int main()
{
    int a = 0;
    int n = 0;
    printf("Input a: ");
    scanf("%i", &a);
    printf("Input n: ");
    scanf("%i", &n);

    if (n == 0)
    {
        printf("Any number in 0 degree = 1");
    }
    else if (n == 1)
    {
        printf("Any number in 1 degree = this number. Answer: %i", a);
    }
    else
    {
        int result = getPow(a, n);
        printf("%i in %i degree = %i", a, n, result);
    }

    return 0;
}