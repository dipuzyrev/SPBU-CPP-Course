#include <stdio.h>

int getFactorial(int number)
{
    if (number > 1)
    {
        return number * getFactorial(number - 1);
    }
    else
    {
        return 1;
    }
}

int getFactorialCycle(int number)
{
    int factorial = 1;
    while (number > 0)
    {
        factorial *= number;
        number--;
    }
    return factorial;
}

int main()
{
    int number = 0;
    printf("Enter an integer number: ");
    scanf("%i", &number);

    //1. Recursion
    int factorial1 = getFactorial(number);

    //2. Cycle
    int factorial2 = getFactorialCycle(number);
    

    printf("%i! = %i\n", number, factorial1);

    return 0;
}