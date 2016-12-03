#include <stdio.h>

void swap(int &a, int &b)
{
    if (a == b)
        return;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void shiftDown(int a[], int i, int j)
{
    int maxNodeId;
    bool shiftDone = false;
    int firstChildIndex = i * 2 + 1;
    int secondChildIndex = i * 2 + 2;

    while (((firstChildIndex) < j) && !shiftDone)
    {
        if (firstChildIndex == j - 1 || a[firstChildIndex] > a[secondChildIndex])
        {
            maxNodeId = firstChildIndex;
        }
        else
        {
            maxNodeId = secondChildIndex;
        }

        if (a[i] < a[maxNodeId])
        {
            swap(a[i], a[maxNodeId]);
            i = maxNodeId;
        }
        else
        {
            shiftDone = true;
        }
    }
}

void pSort(int a[], int l)
{
    int i;
    for (i = (l / 2) - 1; i > -1; i--)
    {
        shiftDown(a, i, l);
    }

    for (i = l - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        shiftDown(a, 0, i);
    }
}

bool test1()
{
    int unsortedArr[10] = {5, -4, 1, 8, 3, 9, 156, -5, 7, -167};
    int sortedArr[10] = {-167, -5, -4, 1, 3, 5, 7, 8, 9, 156};
    pSort(unsortedArr, 10);

    for (int i = 0; i < 10; i++)
        if (unsortedArr[i] != sortedArr[i])
            return false;
    return true;
}

bool test2()
{
    int unsortedArr[15] = {-4, 7, 8, 0, 1, 5, 7, 0, 1, 90, -43, 6, 9, 3, 1};
    int sortedArr[15] = {-43, -4, 0, 0, 1, 1, 1, 3, 5, 6, 7, 7, 8, 9, 90};
    pSort(unsortedArr, 15);

    for (int i = 0; i < 15; i++)
        if (unsortedArr[i] != sortedArr[i])
            return false;
    return true;
}

bool testing()
{
    return (test1() && test2());
}

int main()
{
    bool result = testing();
    if (result)
        printf("All automatic tests done successful.\n");

    int len = 0;
    printf("You can input your own array. Please, input length of array: ");
    scanf("%i", &len);

    int *arr = new int[len];
    printf("Please, input values:\n");

    for (int i = 0; i < len; i++)
        scanf("%i", &arr[i]);

    pSort(arr, len);

    for (int i = 0; i < len; i++)
        printf("%i, ", arr[i]);

    delete [];
}