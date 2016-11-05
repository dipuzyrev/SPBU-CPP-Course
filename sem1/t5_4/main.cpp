#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

void printInstructions()
{
    cout << "0: exit" << endl;
    cout << "1: add entry (name and telephone)" << endl;
    cout << "2: find telephone by name" << endl;
    cout << "3: find name by telephone" << endl;
    cout << "4: save data in file" << endl << endl;
}

void performCommand(List *list, int commandNumber)
{
    switch (commandNumber)
    {
        case 1:
        {
            cout << "Input name: ";
            char *name = createStr(64);
            cin >> name;
            cout << "Input telephone: ";
            char *telephone = createStr(64);
            cin >> telephone;
            int result = addValue(list, name, telephone);
            if (result == 0)
                cout << "Entry was added" << endl << endl;
            else if (result == 1)
                cout << "Telephone (" << telephone << ") already exist" << endl << endl;
            break;
        }
        case 2:
        {
            char *name = createStr(64);
            cout << "Input name: ";
            cin >> name;
            char *result = findByName(list, name);
            if (result != nullptr)
                cout << "Telephone: " << result << endl << endl;
            else
                cout << "Name doesn't exist in the phonebook" << endl << endl;
            break;
        }
        case 3:
        {
            char *telephone = createStr(64);
            cout << "Input telephone: ";
            cin >> telephone;
            char *result = findByTelephone(list, telephone);
            if (result != nullptr)
                cout << "Name: " << result << endl << endl;
            else
                cout << "Telephone doesn't exist in the phonebook" << endl << endl;
            break;
        }
        case 4:
        {
            saveDataToFile(list);
            cout << "Data saved to file" << endl << endl;
            break;
        }
    }
}

int getCommand()
{
    int command = 0;
    cout << endl << "Input your command: ";
    cin >> command;

    if (command > 4 || command < 0)
    {
        cout << "Unknown command number!" << endl;
        return getCommand();
    }
    else
        return command;
}

int main()
{
    List *phonebook = createList();
    loadDataFromFile(phonebook);

    printInstructions();

    int command = getCommand();

    while (command != 0)
    {
        performCommand(phonebook, command);
        command = getCommand();
    }

    return 0;
}
