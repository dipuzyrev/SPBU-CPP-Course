#include <stdio.h>

int main()
{
  int number = 0;
  printf("Enter number: ");
  scanf("%i", &number);

  bool *sieve = new bool[number - 1];

  //false - isn't strike
  for (int i = 0; i < number - 1; i++)
  {
    sieve[i] = false;
  }

  for (int i = 0; i < number - 1; i++)
  {
    int value = i + 2;
    if (!sieve[i]) //isn't strike
    {
      for (int j = i + value; j < number - 1; j += value)
      {
        sieve[j] = true; //strike
      }
    }
  }

  for (int i = 0; i < number - 1; i++)
  {
    int value = i + 2;
    if (!sieve[i])
    {
      printf("%i, ", value);
    }
  }

  delete[] sieve;

  return 0;
}