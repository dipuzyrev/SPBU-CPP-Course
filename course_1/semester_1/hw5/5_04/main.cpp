#include <iostream>
#include <fstream>
#include "List.h"
#include "Phonebook.h"

using namespace std;

enum Command
{
    exitCommand = 0,
    addEntryCommand = 1,
    findTelCommand = 2,
    findNameCommand = 3,
    saveToFileCommand = 4
};

void printInstructions()
{
    cout << exitCommand << ": exit" << endl;
    cout << addEntryCommand << ": add entry (name and telephone)" << endl;
    cout << findTelCommand << ": find telephone by name" << endl;
    cout << findNameCommand << ": find name by telephone" << endl;
    cout << saveToFileCommand << ": save data in file" << endl << endl;
}

void performCommand(List *list, int commandNumber, char const *fileName)
{
    switch (commandNumber)
    {
        case addEntryCommand:
        {
            cout << "Input name: ";
            char name[64] = {'\0'};
            cin >> name;
            cout << "Input telephone: ";
            char telephone[64] = {'\0'};
            cin >> telephone;
            int result = addValue(list, name, telephone);
            if (result)
                cout << "Entry added" << endl << endl;
            else
                cout << "Telephone (" << telephone << ") already exist" << endl << endl;
            break;
        }
        case findTelCommand:
        {
            char name[64] = {'\0'};
            cout << "Input name: ";
            cin >> name;
            char *result = findByName(list, name);
            if (result != nullptr)
                cout << "Telephone: " << result << endl << endl;
            else
                cout << "Name doesn't exist in the phonebook" << endl << endl;
            break;
        }
        case findNameCommand:
        {
            char telephone[64] = {'\0'};
            cout << "Input telephone: ";
            cin >> telephone;
            char *result = findByTelephone(list, telephone);
            if (result != nullptr)
                cout << "Name: " << result << endl << endl;
            else
                cout << "Telephone doesn't exist in the phonebook" << endl << endl;
            break;
        }
        case saveToFileCommand:
        {
            saveDataToFile(fileName, list);
            cout << "Data saved to file" << endl << endl;
            break;
        }
    }
}

int getCommand()
{
    int command = 0;
    cout << "Input your command: ";
    cin >> command;

    if (command != exitCommand && command != addEntryCommand && command != findTelCommand &&
        command != findNameCommand && command != saveToFileCommand)
    {
        cout << "Unknown command number!" << endl;
        return getCommand();
    }
    else
        return command;
}

int main()
{
    char const *fileName = "phonebook.txt";
    List *phonebook = createList();
    loadDataFromFile(fileName, phonebook);

    printInstructions();

    int command = getCommand();

    while (command != exitCommand)
    {
        performCommand(phonebook, command, fileName);
        command = getCommand();
    }

    clearList(phonebook);
    delete phonebook;

    return 0;
}
