#include <stdio.h>

void reverseArray(int arr[], int startIndex, int endIndex)
{
  int middleIndex = (startIndex + endIndex) / 2;


  for (int i = startIndex; i <= middleIndex; i++)
  {
    int tempValue = arr[i];
    arr[i] = arr[endIndex - i + startIndex];
    arr[endIndex - i + startIndex] = tempValue;
  }
}

int main()
{
  //Incoming info
  int x[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  const int m = 4;
  const int n = 6;

  //1. Reverse elements from 0 to m
  reverseArray(x, 0, m);

  //2. Reverse elements from m + 1 to m + n - 1
  reverseArray(x, m + 1, m + n - 1);

  //3. Reverse all array
  reverseArray(x, 0, m + n - 1);

  //Print array for viewing result
  for (int i = 0; i < m + n; i++)
  {
    printf("%i, ", x[i]);
  }

  return 0;
}