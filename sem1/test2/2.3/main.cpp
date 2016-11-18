#include <iostream>
#include <fstream>

using namespace std;

struct QueueElement
{
    QueueElement *next;
    int num;
};

struct NumbersQueue
{
    QueueElement *head;
    QueueElement *last;
};

NumbersQueue *createList()
{
    NumbersQueue *l = new NumbersQueue;
    l->head = nullptr;
    l->last = nullptr;
}

void addNumber(int value, NumbersQueue *l)
{
    QueueElement *newElem = new QueueElement;
    newElem->next = nullptr;
    newElem->num = value;

    if (l->last == nullptr)
    {
        l->head = newElem;
        l->last = newElem;
    }
    else
        l->last->next = newElem;

    l->last = newElem;
}

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
    fin.close();
    fout.close();

    return 0;
}
