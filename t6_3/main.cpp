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

int main()
{
    int coefficients[] = {-112, -5, 561, 9};
    int length = 4;

    //print 1 line

    for (int i = length - 1; i > 1; i--)
    {
        int coeffLength = getNumberLength(coefficients[length - i - 1]);
//        int degreeLenght = getNumberLength(i);
        int indent = coeffLength;

        if (i != length - 1)
            indent += 3;
        else
            if (coefficients[0] < 0)
                indent++;

        printSpaces(indent);
        cout << i;
    }
    cout << endl;

    for (int i = length - 1; i >= 0; i--)
    {
        if (i == length - 1)
            cout << coefficients[0] << "x";
        else
        {
            if (coefficients[length - i - 1] < 0)
                cout << " - " << -coefficients[length - i - 1];
            else
                cout << " + " << coefficients[length - i - 1];
            if (i != 0)
                cout << "x";
        }
    }
    cout << endl << endl;

    return 0;
}
