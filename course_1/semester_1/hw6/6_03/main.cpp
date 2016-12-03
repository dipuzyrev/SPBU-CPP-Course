#include <iostream>

using namespace std;

int getNumberLength(int number)
{
    int length = 0;

    while (number != 0)
    {
           number /= 10;
           length++;
    }

    return length;
}

void printSpaces(int count)
{
    for (int i = 0; i < count; i++)
        cout << " ";
}
//int getMax(int n1, int n2);

void inputCoefficients(int coefficients[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Enter " << i << "th coefficient: ";
        cin >> coefficients[length - 1 - i];
    }

    cout << endl;
}

void printPowers(int length, int coefficients[])
{
    cout << " ";
    for (int i = length - 1; i > 1; i--)
    {
        int coeff = coefficients[length - i - 1];

        if (coeff == 0)
            continue;

        int coeffLength = getNumberLength(coeff);
        int indent = coeffLength;

        if (i != length - 1)
            indent = (coeff == 1 || coeff == -1) ? indent + 2 : indent + 3;
        else
            if (coefficients[0] < 0 && coeff != -1)
                indent++;

        printSpaces(indent);
        cout << i;
    }
}

void printCoefficients(int length, int coefficients[])
{
    if (coefficients[0])
        if (coefficients[0] == 1)
            cout << "x";
        else if (coefficients[0] == -1)
            cout << "-x";
        else
            cout << coefficients[0] << "x";

    int lastDegree = length - 2;
    for (int i = length - 2; i >= 0; i--)
    {
        if (coefficients[length - i -1] == 0)
            continue;

        int degreeLenght = getNumberLength(lastDegree);
        printSpaces(degreeLenght - 1);
        lastDegree = i;

        if (coefficients[length - i - 1] < 0)
        {
            cout << " - ";
            if (coefficients[length - i - 1] != -1 || i == 0)
                cout << -coefficients[length - i - 1];
        }
        else
        {
            cout << " + ";
            if (coefficients[length - i - 1] != 1 || i == 0)
                cout << coefficients[length - i - 1];
        }
        if (i != 0)
            cout << "x";
    }
}

int main()
{
    cout << "Enter coefficients count: ";
    int length = 0;
    cin >> length;
    int coefficients[length] = {0};
    inputCoefficients(coefficients, length);

    printPowers(length, coefficients);
    cout << endl;

    printCoefficients(length, coefficients);
    cout << endl;

    return 0;
}
