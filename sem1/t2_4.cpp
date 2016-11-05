#include <stdio.h>

int **arrayGenerator(int length1, int length2)
{
    int **fractions = new int * [length1];
    for (int i = 0; i < length1; i++) {
        fractions[i] = new int [length2];
    }
    return fractions;
}

void arrayDestroyer(int **arr, int length1)
{
    for (int i = 0; i < length1; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void insertLeft(int **arr, int index, int count, int n1, int n2)
{
    int tempFraction[2] = {arr[index][0], arr[index][1]};
    arr[index][0] = n1;
    arr[index][1] = n2;

    int i = count;
    for (; i > index; i--)
    {
        arr[i][0] = arr[i - 1][0];
        arr[i][1] = arr[i - 1][1];
    }

    arr[i + 1][0] = tempFraction[0];
    arr[i + 1][1] = tempFraction[1];
}

void insertRight(int **arr, int index, int count, int n1, int n2)
{
    int tempFraction[2] = {arr[index + 1][0], arr[index + 1][1]};
    arr[index + 1][0] = n1;
    arr[index + 1][1] = n2;

    int i = count;
    for (; i > index + 2; i--)
    {
        arr[i][0] = arr[i - 1][0];
        arr[i][1] = arr[i - 1][1];
    }

    arr[index + 2][0] = tempFraction[0];
    arr[index + 2][1] = tempFraction[1];
}

void generateFractions(int **arr, int elementsCount, int maxDenominator)
{
    bool isInserted = false;
    int newElementsCount = elementsCount;

    for (int i = 0; i < elementsCount; i++)
    {
        int currentNumber = arr[i][0];
        int currentDenominator = arr[i][1];
        int leftDenominator = 0;
        int rightDenominator = 0;
        int leftNumber = 0;
        int rightNumber = 0;
        if (i == 0)
        {
            leftNumber = 0;
            leftDenominator = 1;
        }
        else
        {
            leftNumber = arr[i - 1][0];
            leftDenominator = arr[i - 1][1];
        }

        if (i == elementsCount - 1)
        {
            rightNumber = 1;
            rightDenominator = 1;
        }
        else
        {
            rightNumber = arr[i + 1][0];
            rightDenominator = arr[i + 1][1];
        }

        if (maxDenominator >= leftDenominator + currentDenominator)
        {
            insertLeft(arr, i, newElementsCount, leftNumber + currentNumber, leftDenominator + currentDenominator);
            isInserted = true;
            newElementsCount++;
            i++;
        }

        if (maxDenominator >= rightDenominator + currentDenominator)
        {
            insertRight(arr, i, newElementsCount, rightNumber + currentNumber, rightDenominator + currentDenominator);
            isInserted = true;
            newElementsCount++;
            i++;
        }
    }

    if (isInserted)
        generateFractions(arr, newElementsCount, maxDenominator);
}

int main()
{
    int n = 0;
    printf("Enter n: ");
    scanf("%i", &n);

    const int size = 1024;
    int **numbers = arrayGenerator(size, 2);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < 2; j++)
            numbers[i][j] = 0;

    numbers[0][0] = 1;
    numbers[0][1] = 2;
    generateFractions(numbers, 1, n);

    int i = 0;
    while (numbers[i][0] != 0 && numbers[i][1] != 0)
    {
        printf("%i/%i, ", numbers[i][0], numbers[i][1]);
        i++;
    }
    printf("\n");

    arrayDestroyer(numbers, size);
    return 0;
}