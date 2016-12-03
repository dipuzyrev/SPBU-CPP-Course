#include <iostream>

using namespace std;

void printSum(int index, int *numbers)
{
    cout << numbers[0];
    for (int i = 1; i <= index; i++)
        cout << " + " << numbers[i];
    cout << endl;
}

void printSums(int currentIndex, int numbersIndex, int sum, int n, int *numbers)
{
    for (int i = currentIndex; i < n; i++)
    {
        numbers[numbersIndex] = i;
        if (sum + i == n)
            printSum(numbersIndex, numbers);
        else if (sum + i < n)
            printSums(i, numbersIndex + 1, sum + i, n, numbers);
    }
}

int main()
{
    int n = 0;
    cout << "Input N: ";
    cin >> n;

    int *numbers = new int[n];
    for (int i = 0; i < n; i++)
        numbers[i] = 0;

    printSums(1, 0, 0, n, numbers);

    delete[] numbers;
    return 0;
}