#include <stdio.h>

int fiboRecursion(int elemNumber)
{
  if (elemNumber == 1)
  {
    return 0;
  }
  else if (elemNumber == 2)
  {
    return 1;
  }
  else
  {
    return fiboRecursion(elemNumber - 1) + fiboRecursion(elemNumber - 2);
  }
}

int fiboCycle(int elemNumber)
{
  if (elemNumber == 1)
  {
    return 0;
  }
  else if (elemNumber == 2)
  {
    return 1;
  }
  else
  {
    int penultNum = 0;
    int lastNum = 1;
    int currentElemNum = 3;
    while (currentElemNum <= elemNumber)
    {
      currentElemNum++;
      lastNum += penultNum;
      penultNum = lastNum - penultNum;
    }

    return lastNum;
  }
}

int main()
{
  int elemNumber = 0;
  printf("Enter number of Fibonacci element (1:0, 2:1, 3:1, 4:2, ...): ");
  scanf("%i", &elemNumber);

  //Recursion
  int fibo1 = fiboRecursion(elemNumber);

  //Cycle
  int fibo2 = fiboCycle(elemNumber);

  printf("Your Fibonacci number: %i\n", fibo1);
  printf("Your Fibonacci number(cycle): %i", fibo2);

  return 0;
}