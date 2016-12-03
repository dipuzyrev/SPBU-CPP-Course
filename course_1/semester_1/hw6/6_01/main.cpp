#include <iostream>

using namespace std;

char getSign(double num)
{
    unsigned char *bin = (unsigned char*)(&num);

    int signMask = 0b10000000;
    bool negative = false;

    if (bin[7] & signMask)
        negative = true;

    return negative ? '-' : '+';
}

double getMantissa(double num)
{
    unsigned char *bin = (unsigned char*)(&num);

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

    return mantissaDec;
}

int getExponent(double num)
{
    unsigned char *bin = (unsigned char*)(&num);

    int exponentMask = 0b00010000;
    int bitsToCheck = 4;
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

    return exponentDec;
}

void printExponential(double num)
{
    char sign = getSign(num);
    double mantissa = getMantissa(num);
    int exponent = getExponent(num);

    cout << sign << mantissa << " * 2 ^ " << exponent << endl;
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
