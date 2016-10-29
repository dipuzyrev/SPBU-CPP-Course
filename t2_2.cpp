#include <stdio.h>

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

int main()
{
    const int size = 5;
    int unsorted[size] = {0};
    printf("Enter %i elements to array:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%i", &unsorted[i]);

    qSort(0, size - 1, unsorted);

    for (int i = 0; i < size; i++)
    {
        printf("%i, ", unsorted[i]);
    }

    return 0;
}