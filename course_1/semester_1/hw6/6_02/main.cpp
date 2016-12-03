#include <iostream>

using namespace std;

void sumBin(int *bin1, int *bin2, int *binSum)
{
    int additional = 0;

    for (int i = 7; i >= 0; i--)
    {
        int sum = bin1[i] + bin2[i] + additional;
        if (sum < 2)
            binSum[i] = sum;
        else
        {
            binSum[i] = sum % 2;

            if (i == 0)
            {
                int toAdd[8] = {0,0,0,0,0,0,0,1};
                sumBin(binSum, toAdd, binSum);
            }

            additional = 1;
        }
    }
}

void inverseBin(int *bin)
{
    for (int i = 0; i < 8; i++)
        bin[i] = (bin[i] + 1) % 2;
}

void decToBin(int dec, int *bin)
{
    int pattern = 0b10000000;

    bool inverse = dec < 0;
    if (inverse)
        dec = -dec;

    for (int i = 0; i < 8; i++)
    {
        bin[i] = (dec & pattern) > 0 ? 1 : 0;
        pattern = pattern >> 1;
    }

    if (inverse)
        inverseBin(bin);
}

void printBin(int *bin, char const *message)
{
    cout << message << " ";
    for (int i = 0; i < 8; i++)
        cout << bin[i];
    cout << endl;
}

int pow(int n, int power)
{
    if (power == 0)
        return 1;

    for (int i = 1; i < power; i++)
        n *= n;

    return n;
}

int binToDec(int *bin)
{
    bool inverse = bin[0] == 1;

    if (inverse)
        inverseBin(bin);

    int dec = 0;

    for (int i = 7; i >= 0; i--)
        dec += bin[7 - i] * pow(2, i);

    return inverse ? -dec : dec;
}

int main()
{

    int number1 = 0;
    int number2 = 0;

    cout << "Number's sum must be from -127 to 127!" << endl;
    cout << "To binary numbers used inversed code." << endl << endl;

    cout << "Input first number: ";
    cin >> number1;

    cout << "Input second number: ";
    cin >> number2;

    int binary1[8] = {0};
    int binary2[8] = {0};
    int binarySum[8] = {0};

    decToBin(number1, binary1);
    decToBin(number2, binary2);
    printBin(binary1, "Number 1:");
    printBin(binary2, "Number 2:");

    sumBin(binary1, binary2, binarySum);
    printBin(binarySum, "Binary sum: ");
    cout << "Decimal sum: " << binToDec(binarySum) << endl;

    return 0;
}
