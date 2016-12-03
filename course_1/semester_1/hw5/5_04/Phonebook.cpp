#include <iostream>
#include <fstream>
#include "Phonebook.h"
#include "List.h"

using namespace std;

void loadDataFromFile(char const *fileName, List *l)
{
    ifstream fin(fileName);

    if (!fin.is_open())
        return;

    char name[64] = {'\0'};
    char telephone[64] = {'\0'};

    fin >> name;
    fin >> telephone;

    if (name[0] != '\0' && telephone[0] != '\0')
        addValue(l, name, telephone);

    while (!fin.eof())
    {
        fin >> name;
        fin >> telephone;
        addValue(l, name, telephone);
    }

    fin.close();
}

void saveDataToFile(char const *fileName, List *l)
{
    ofstream fout("phonebook.txt");

    while (!isEmpty(l))
    {
        char *name = getHeadName(l);
        char *telephone = getHeadTelephone(l);

        fout << name << endl;
        fout << telephone << endl;

        deleteHead(l);
    }

    fout.close();
}
