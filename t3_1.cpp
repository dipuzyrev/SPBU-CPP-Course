#include <iostream>

using namespace std;

void inputData(int &x, int &n)
{
    printf("Input number: ");
    scanf("%i", &x);
    printf("Input degree: ");
    scanf("%i", &n);
}

void printResult(int value)
{
    if (value < 0)
    {
        printf("Your result: 1/%i", abs(value));
    }
    else
    {
        printf("Your result: %i\n", value);
    }
}

int pow(int x, int n)
{
    int y = 1;

    while (n)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            x *= x;
        }
        else
        {
            n--;
            y *= x;
        }
    }

    return y;
}

int main()
{
    int x = 0;
    int n = 0;
    inputData(x, n);

    if (n > 0)
    {
        int result = pow(x, n);
        printResult(result);
    }
    else if (n < 0)
    {
        int result = pow(x, abs(n));
        printResult(-result); //для спец. форматирования в printResult
    }
    else
        printResult(1);

    return 0;
}