#include <iostream>

using namespace std;

void printExponential(double num)
{
    unsigned char *bin = (unsigned char*)(&num);

    int counter = 0;

    for (int i = 0; i < 8; i++)
    {

        int mask = 0b00000001;

        for (int j = 0; j < 8; j++)
        {
            if (counter == 63 || counter == 52)
                cout << "_";

            if (counter % 8 == 0)
                cout << " | ";

            if (bin[i] & mask)
                cout << 1;
            else
                cout << 0;

            mask = mask << 1;
            counter++;
        }
    }

    cout << endl << endl;
}

int main()
{
    double num = 0;
    cout << "Enter number: ";
    cin >> num;

    cout << "Exponential form: ";
    printExponential(num);

    return 0;
}
