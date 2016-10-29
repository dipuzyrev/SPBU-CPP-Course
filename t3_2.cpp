#include <iostream>

bool isUnique(int number, int *arr)
{
    int i = 0;
    while(arr[i] != 0)
    {
        if (arr[i] == number)
            return false;
        i++;
    }
    return true;
}


void addNumber(int number, int *arr)
{
    int i = 0;
    while(arr[i] != 0)
        i++;
    arr[i] = number;
}

int main()
{
    int arrayLength = 0;
    printf("Array length: ");
    scanf("%i", &arrayLength);
    int *numbers = new int[arrayLength];
    for (int i = 0; i < arrayLength; i++)
        numbers[i] = 0;
    for (int i = 0; i < arrayLength; i++)
        scanf("%i", &numbers[i]);

    int *uniqueNumbers = new int[arrayLength];
    bool zeroExist = false;

    for (int i = 0; i < arrayLength; i++)
        uniqueNumbers[i] = 0;

    int maxNumber = 0;
    bool maxNumberInit = false;

    for (int i = 0; i < arrayLength; i++)
    {
        if (numbers[i] != 0)
        {

            if (isUnique(numbers[i], uniqueNumbers))
                addNumber(numbers[i], uniqueNumbers);
            else
                if (maxNumber == 0 || maxNumber < numbers[i] || !maxNumberInit)
                {
                    maxNumber = numbers[i];
                    maxNumberInit = true;
                }
        }
        else
        {
            if(zeroExist)
            {
                if (maxNumber < 0 || !maxNumberInit)
                {
                    maxNumber = 0;
                    maxNumberInit = true;
                }
            }
            else
            {
                zeroExist = true;
            }
        }
    }

    delete[] numbers;
    delete[] uniqueNumbers;

    if (maxNumberInit)
        printf("Max number: %i\n", maxNumber);
    else
        printf("All numbers are unique.\n");

    return 0;
}