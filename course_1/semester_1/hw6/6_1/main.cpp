#include <iostream>

using namespace std;

void printExponential(double num)
{
    unsigned char *bin = (unsigned char*)(&num);

    int signMask = 0b10000000;
    bool negative = false;

    if (bin[7] & signMask)
        negative = true;

    double mantissaDec = 1;

    int mask = 0b00001000; //to start from 51'th bit
    int bitsToCheck = 4;
    long long int denominator = 2;

    for (int i = 6; i >= 0; i--)
    {
        for (int j = 0; j < bitsToCheck; j++)
        {
            if (bin[i] & mask)
            {
                double toAdd = (double) 1 / denominator;
                mantissaDec += toAdd;
            }

            denominator *= 2;
            mask = mask >> 1;
        }

        mask = 0b10000000;
        bitsToCheck = 8;
    }

    int exponentMask = 0b00010000;
    bitsToCheck = 4;
    int exponentDec = 0;
    int factor = 1;

    for (int i = 6; i <= 7; i++)
    {
        for (int j = 0; j < bitsToCheck; j++)
        {
            if (bin[i] & exponentMask)
            {
                exponentDec += factor;
            }

            factor *= 2;
            exponentMask = exponentMask << 1;
        }

        exponentMask = 0b00000001;
        bitsToCheck = 7;
    }

    exponentDec -= 1023;

    if (negative)
        cout << "-";
    else
        cout << "+";

    cout << mantissaDec << "^" << "2*" << exponentDec;
}

int main()
{
    cout.precision(20);

    double num = 0;
    cout << "Enter number: ";
    cin >> num;

    cout << "Exponential form: ";
    printExponential(num);
    cout << endl;

    return 0;
}
