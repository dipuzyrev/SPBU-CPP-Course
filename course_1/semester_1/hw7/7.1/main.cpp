#include <iostream>
#include "BinaryTree.h"

using namespace std;

void performAutomaticTest()
{
    BinaryTree *bsw = create();
    addValue(20, bsw);
    addValue(10, bsw);
    addValue(5, bsw);
    addValue(3, bsw);
    addValue(7, bsw);
    addValue(6, bsw);
    addValue(8, bsw);
    addValue(15, bsw);
    addValue(13, bsw);
    addValue(12, bsw);
    addValue(14, bsw);
    addValue(17, bsw);
    addValue(30, bsw);
    addValue(25, bsw);
    addValue(50, bsw);
    addValue(100, bsw);
    addValue(75, bsw);

    cout << "In ascending: ";
    print(1, bsw);

    cout << endl << "In descending: ";
    print(2, bsw);

    cout << endl << "Detail structure: ";
    print(3, bsw);

    cout << endl << "Delete value 15 and print in ascending: ";
    deleteValue(15, bsw);
    print(1, bsw);

    cout << endl << "Is value 15 in tree?: ";
    if (contains(15, bsw))
        cout << "YES";
    else
        cout << "NO";

    cout << endl << "Clear tree and print in detail structure: ";
    clear(bsw);
    print(3, bsw);
    cout << endl;
}

void printInstructions()
{
    cout << "0: exit" << endl;
    cout << "1: add a value to binary tree" << endl;
    cout << "2: remove value from binary tree" << endl;
    cout << "3: check if value contains in tree" << endl;
    cout << "4: print binary tree" << endl;
}

void performCommand(BinaryTree *bsw, int commandNumber)
{
    if (commandNumber == 1)
    {
        int value = 0;
        cout << "Input value to add: ";
        cin >> value;
        bool result = addValue(value, bsw);
        if (result)
            cout << "Value (" << value << ") added" << endl;
        else
            cout << "Value (" << value << ") already exist" << endl;
    }
    else if (commandNumber == 2)
    {
        int value = 0;
        cout << "Input value to remove: ";
        cin >> value;
        bool result = deleteValue(value, bsw);
        if (result)
            cout << "Value (" << value << ") removed" << endl;
        else
            cout << "Value (" << value << ") not found" << endl;
    }
    else if (commandNumber == 3)
    {
        int value = 0;
        cout << "Input value to check: ";
        cin >> value;
        bool result = contains(value, bsw);
        if (result)
            cout << "Value (" << value << ") contains in tree" << endl;
        else
            cout << "Value (" << value << ") not found" << endl;
    }
    else if (commandNumber == 4)
    {
        int flag = 1;
        cout << "1) in ascending order / 2) in descending order / 3) overall structure : ";
        cin >> flag;
        print(flag, bsw);
        cout << endl;
    }
    else if (commandNumber == -1)
        cout << "Uncorrect command! To exit input 0" << endl;
}

int getCommand()
{
    int command = 0;
    cout << endl << "Input your command: ";
    cin >> command;

    if (command > 4 || command < 0)
        return -1;
    else
        return command;
}

int main()
{
    //performAutomaticTest();

    BinaryTree *bsw = create();

    printInstructions();
    int command = getCommand();

    while (command != 0)
    {
        performCommand(bsw, command);
        command = getCommand();
    }

    clear(bsw);
    delete bsw;
    return 0;
}
