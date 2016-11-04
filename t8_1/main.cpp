#include <iostream>

using namespace std;

int getCopy(int studentNumber, int *couples)
{
    int copy = couples[studentNumber - 1];

    if (!copy)
        return 0;

    if (copy >= 1 && copy <= 3)
        return copy;
    else
        return getCopy(copy, couples);
}

int main()
{
    int count = 0;

    cout << "Input count of students: ";
    cin >> count;
    int *couples = new int[count];
    for (int i = 0; i < count; i++)
        couples[i] = 0;

    int studentNumber = 0;
    int studentCopyNumber = 0;

    cout << endl << "Couples input format: [studentNumber studentCopyNumber] (for example \"4 2\")" << endl;
    cout << "To finish inputting click \"0\"" << endl << endl;


    for (int i = 1; i <= count - 3; i++)
    {
        cout << "Input " << i << "\'th couple: ";
        cin >> studentNumber;
        if (studentNumber == 0)
            break;
        cin >> studentCopyNumber;
        couples[studentNumber - 1] = studentCopyNumber;
    }

    cout << endl << "Answer: " << endl;

    for (int i = 3; i < count; i++)
    {
        int student = i + 1;
        int copy = getCopy(student, couples);

        if (copy)
            cout << student << " " << copy << endl;
        else
            cout << student << " did nothing!" << endl;
    }

    cout << endl;
    delete[] couples;
    return 0;
}
