#include <iostream>
#include <stdio.h>
#include <ctime>

void swap(int index1, int index2, int array[])
{
    int value1 = array[index1];
    array[index1] = array[index2];
    array[index2] = value1;
}

void qSort(int leftIndex, int rightIndex, int array[])
{
    if (leftIndex == rightIndex) //there is 1 element - nothing to sort
    {
        return;
    }
    else if (leftIndex == (rightIndex - 1)) //only 2 elements - easy to sort
    {
        if (array[leftIndex] > array[rightIndex])
        {
            swap(leftIndex, rightIndex, array);
        }
        return;
    }

    int base = leftIndex;
    int i = leftIndex + 1;
    int j = rightIndex;

    while (i < j)
    {
        if (array[i] >= array[base])
        {
            if (array[j] < array[base])
            {
                swap(i, j, array);
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }

    swap(base, i - 1, array);

    qSort(leftIndex, i - 1, array);
    qSort(i, rightIndex, array);
    return;
}

int inputIntNum(char message[])
{
    int result = 0;
    printf("%s ", message);
    scanf("%i", &result);
    return result;
}

void initIntArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
        array[i] = -1;
}

int generateRandomNumber(int min, int max)
{
    return (rand() % (max - min)) + min + 1;
}

void generateRandomArray(int array[], int length, int min, int max)
{
    for (int i = 0; i < length; i++)
        array[i] = generateRandomNumber(min, max);
}

bool exist(int number, int array[], int arrayLength)
{
    int firstIndex = 0;
    int lastIndex = arrayLength - 1;
    int averageIndex = 0;
    while (firstIndex < lastIndex)
    {
        averageIndex = firstIndex + (lastIndex - firstIndex) / 2;
        if (number <= array[averageIndex])
            lastIndex = averageIndex;
        else
            firstIndex = averageIndex + 1;
    }
    if ( array[lastIndex] == number)
        return true;
    else
        return false;
}

int main()
{
    const int minN = 1;
    const int maxN = 5000;
    const int minK = 1;
    const int maxK = 300000;
    const int minRandom = 0;
    const int maxRandom = 1000000000;

    srand(time(0));

    int n = inputIntNum("Input (n):");
    int k = inputIntNum("Input (k):");

    int *randomNumbers = new int[n];
    initIntArray(randomNumbers, n);
    generateRandomArray(randomNumbers, n, minRandom, maxRandom);
    qSort(0, n - 1, randomNumbers);

    for (int i = 0; i < k; i++)
    {
        int randomNumber = generateRandomNumber(minRandom, maxRandom);
        if (exist(randomNumber, randomNumbers, n))
            printf("%i exist\n", randomNumber);
        else
            printf("%i not exist\n", randomNumber);
    }

    delete[] randomNumbers;
    return 0;
}