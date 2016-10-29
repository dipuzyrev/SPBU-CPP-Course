#include <iostream>
#include <stdio.h>
#include <ctime>

bool isInArr(int arr[], int len, int num)
{
    for (int i = 0; i < len; i++)
        if (arr[i] == num)
            return true;
    return false;
}

void printNumber(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%i", arr[i]);
    printf("\n");
}

void genRandomNums(int arr[], int len)
{
    srand(time(0));
    for (int i = 0; i < len; i++)
    {
        int number = rand() % 9 + 1;
        if (!isInArr(arr, len, number))
            arr[i] = number;
        else
            i--;
    }
}

bool compare(int arr1[], int arr2[], int len)
{
    for (int i = 0; i < len; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

void inputUserNumber(int arr[])
{
    int number = 0;
    printf("Input your number: ");
    scanf("%i", &number);

    arr[3] = number % 10;
    arr[2] = (number % 100) / 10;
    arr[1] = (number % 1000) / 100;
    arr[0] = number / 1000;
}

void printResult(int userNums[], int rightNums[], int len)
{
    int cows = 0;
    int bulls = 0;

    if (!compare(userNums, rightNums, 4))
    {
        for (int i = 0; i < len; i++)
        {
            if (userNums[i] == rightNums[i])
                bulls++;
            else if (isInArr(rightNums, 4, userNums[i]))
                cows++;
        }
        printf("%i bulls, %i cows\n\n", bulls, cows);
    }

}

int main()
{
    int nums[4] = {-1};
    genRandomNums(nums, 4);

    //hint to debug
    printNumber(nums, 4);
    printf("\n");

    int userNums[4] = {-1};
    while(!compare(nums, userNums, 4))
    {
        inputUserNumber(userNums);
        printResult(userNums, nums, 4);
    }

    printf("Yes, number is: ");
    printNumber(nums, 4);

    //printArr(nums, 4);

    return 0;
}