#include <iostream>

using namespace std;

void swap(int index1, int index2, int arr[])
{
    int value1 = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = value1;
}

void qSort(int leftIndex, int rightIndex, int arr[])
{
    if (leftIndex == rightIndex) //there is 1 element - nothing to sort
        return;

    if (leftIndex == (rightIndex - 1)) //only 2 elements - easy to sort
    {
        if (arr[leftIndex] > arr[rightIndex])
            swap(leftIndex, rightIndex, arr);
        return;
    }

    int base = leftIndex;
    int i = leftIndex + 1;
    int j = rightIndex;

    while (i < j)
        if (arr[i] > arr[base])
            if (arr[j] <= arr[base])
                swap(i, j, arr);
            else
                j--;
        else
            i++;

    if (i == rightIndex)
    {
        if (arr[i] >= arr[base])
        {
            swap(base, i - 1, arr);
            qSort(leftIndex, rightIndex - 1, arr);
        }
        else
        {
            swap(base, i, arr);
            qSort(leftIndex, rightIndex - 1, arr);
        }
        return;
    }

    swap(base, i - 1, arr);

    qSort(leftIndex, i - 1, arr);
    qSort(i, rightIndex, arr);
    return;
}

int getLevelsCount(int n)
{
    int result = 1;
    while (n / 10 != 0)
    {
        result++;
        n /= 10;
    }
    return result;
}

int main()
{
    int n = 0;
    printf("Input number: ");
    scanf("%i", &n);

    int count = getLevelsCount(n);
    int* levels = new int[count];
    for (int i = 0; i < count; i++)
    {
        levels[i] = n % 10;
        n /= 10;
    }

    qSort(0, count - 1, levels);

    int zeroes = 0;
    bool zeroesPrinted = true;

    for (int i = 0; i < count; i++)
    {
        if (levels[i] == 0)
        {
            zeroes++;
            zeroesPrinted = false;
        }
        else
        {
            if (zeroes && !zeroesPrinted)
            {
                printf("%i", levels[i]);
                for (int j = 0; j < zeroes; j++)
                {
                    printf("0");
                }
                zeroesPrinted = true;
                continue;
            }
            else
            {
                printf("%i", levels[i]);
            }
        }
    }

    delete[] levels;
    return 0;
}