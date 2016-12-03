#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;

int charToInt(char *str)
{
    int i = 0;
    int newNumber = 0;

    while (i < 1024 && (int) str[i] >= (int) '0' && (int) str[i] <= (int) '9')
    {
        newNumber = newNumber * 10 + ((int) str[i] - (int) '0');
        i++;
    }

    return newNumber;
}

int main()
{
    int a = 0;
    int b = 0;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;

    if (a > b)
    {
        cout << "Uncorrect input!" << endl;
        return 0;
    }

    char const *inputFile = "f.txt";
    char const *outputFile = "g.txt";

    ifstream fin(inputFile);
    ofstream fout(outputFile);

    if (fin.fail())
    {
        cout << "Fail to open file!" << endl;
        return 0;
    }

    char buffer[1024] = {'\0'};
    NumbersQueue *fromAtoB = createList();
    NumbersQueue *fromB = createList();

    while (!fin.eof())
    {
        fin >> buffer;
        int number = charToInt(buffer);
        if (number < a)
            fout << number << " ";
        else if (number >= a && number <= b)
            addNumber(number, fromAtoB);
        else
            addNumber(number, fromB);
    }

    fout << "\n\n";

    if (fromAtoB->head != nullptr)
    {
        QueueElement *temp = fromAtoB->head;

        while (temp != nullptr)
        {
            int value = temp->num;
            fout << value << " ";
            temp = temp->next;
        }
    }

    fout << "\n\n";

    if (fromB->head != nullptr)
    {
        QueueElement *temp = fromB->head;

        while (temp != nullptr)
        {
            int value = temp->num;
            fout << value << " ";
            temp = temp->next;
        }
    }

    delete[] inputFile;
    delete[] outputFile;

    delete fromAtoB;
    delete fromB;

    fin.close();
    fout.close();

    return 0;
}
