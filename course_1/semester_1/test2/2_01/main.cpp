#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    cout << "1: 0, 2: 1, 3:1 ..." << endl;
    cout << "Enter i: ";
    cin >> i;

    int first = 0;
    int second = 1;

    for (int j = 1; j < i; j++)
    {
        int sum = first + second;
        first = second;
        second = sum;
    }

    cout << "Your number: " << first << endl;

    return 0;
}
