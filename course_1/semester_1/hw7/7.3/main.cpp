#include <iostream>
#include "BinaryTree.h"

using namespace std;

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
        addValue(value, bsw);
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
