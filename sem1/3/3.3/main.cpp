#include <iostream>
using namespace std;

void swap(int index1, int index2, char arr[])
{
    char value1 = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = value1;
}

void qSort(int leftIndex, int rightIndex, char arr[])
{
    if (leftIndex == rightIndex) //there is 1 element - nothing to sort
        return;

    if (leftIndex == (rightIndex - 1)) //only 2 elements - easy to sort
    {
        if ((int) arr[leftIndex] > (int) arr[rightIndex])
        {
            swap(leftIndex, rightIndex, arr);
        }
        return;
    }

    int base = leftIndex;
    int i = leftIndex + 1;
    int j = rightIndex;

    while (i < j)
    {
        if ((int) arr[i] >=  (int) arr[base])
        {
            if ((int) arr[j] < (int) arr[base])
            {
                swap(i, j, arr);
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

    if (i == j && i == rightIndex) //base is the largest element
    {
        swap(base, i, arr);
    }
    else
    {
        swap(base, i - 1, arr);
    }


    qSort(leftIndex, i - 1, arr);
    qSort(i, rightIndex, arr);
    return;
}

int getStringLength(char str[])
{
    int i = 0;
    while (str[i])
        i++;

    return i;
}

bool compare(char s1[], char s2[])
{
    int i = 0;
    while (s1[i])
    {
        if (s1[i] != s2[i])
            return false;
        i++;
    }

    return true;
}

int main()
{
    //Algorithm:
    //Sorting both strings with "qSort" by ACII number of character
    //Simple comparing first string with second string

    const int maxStrLength = 1024;
    char s1[maxStrLength] = {'\0'};
    char s2[maxStrLength] = {'\0'};
    cout << "Input FIRST string and click \"Enter\": ";
    cin >> s1;
    cout << "Input SECOND string and click \"Enter\": ";
    cin >> s2;
    cout << endl;

    int length1 = getStringLength(s1);
    int length2 = getStringLength(s2);

    if (length1 != length2)
    {
        printf("Your strings have different lengths.");
        return 0;
    }

    qSort(0, length1 - 1, s1);
    qSort(0, length2 - 1, s2);

    printf("%s\n", compare(s1, s2) ? "Yes" : "No");

    cout << endl;
    return 0;
}