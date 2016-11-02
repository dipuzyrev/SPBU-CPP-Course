#include <iostream>
#include <fstream>

using namespace std;

struct ListItem
{
    ListItem *next;
    char *name;
    char *telephone;
};

struct List
{
    ListItem *head;
    int size;
};

ListItem *createListItem(char *name, char *telephone, ListItem *next)
{
    ListItem *newItem = new ListItem;
    newItem->next = next;
    newItem->name = name;
    newItem->telephone = telephone;
    return newItem;
}
List *createList()
{
    List *newList = new List;
    newList->head = nullptr;
    newList->size = 0;
    return newList;
}

char *createStr(int length)
{
    char *str = new char[length];

    for (int i = 0; i < length; i++)
        str[i] = '\0';
    return str;
}

bool isEmpty(List *l)
{
    return l->size == 0;
}

bool compareCharacters(char *str1, char *str2)
{
    for (int i = 0 ;i < 64; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}

//addValue:
//returns 0 - value added, 1 - value already in the list
int addValue(List *l, char *name, char *telephone)
{
    if (isEmpty(l))
    {
        ListItem *newItem = createListItem(name, telephone, nullptr);
        l->head = newItem;
        l->size++;
        return 0;
    }

    ListItem *temp = l->head;

    while (!compareCharacters(temp->telephone, telephone) && temp->next != nullptr)
        temp = temp->next;

    if (compareCharacters(temp->telephone, telephone))
        return 1;
    else
    {
        ListItem *newItem = createListItem(name, telephone, nullptr);
        temp->next = newItem;
        l->size++;
        return 0;
    }
}

//findByName:
//returns: nullptr - not found or (char) telephone
char *findByName(List *l, char *name)
{
    if (isEmpty(l))
        return nullptr;

    ListItem *temp = l->head;

    while (!compareCharacters(temp->name, name) && temp->next != nullptr)
        temp = temp->next;

    if (!compareCharacters(temp->name, name))
        return nullptr;
    else
        return temp->telephone;
}

//findByTelephone:
//returns: nullptr - not found or (char) name
char *findByTelephone(List *l, char *telephone)
{
    if (isEmpty(l))
        return nullptr;

    ListItem *temp = l->head;

    while (!compareCharacters(temp->telephone, telephone) && temp->next != nullptr)
        temp = temp->next;

    if (!compareCharacters(temp->telephone, telephone))
        return nullptr;
    else
        return temp->name;
}

void loadDataFromFile(List *l)
{
    ifstream fin("phonebook.txt");

    if (!fin.is_open())
        return;

    char *name = createStr(64);
    char *telephone = createStr(64);

    fin >> name;
    fin >> telephone;

    if (name[0] != '\0' && telephone[0] != '\0')
    {
        l->head = createListItem(name, telephone, nullptr);
        l->size++;
    }

    ListItem *temp = l->head;

    fin >> name;
    fin >> telephone;

    while (!fin.eof())
    {
        temp->next = createListItem(name, telephone, nullptr);
        l->size++;
        temp = temp->next;
        fin >> name;
        fin >> telephone;
    }

    fin.close();
}

void saveDataToFile(List *l)
{
    ofstream fout("phonebook.txt");

    ListItem *temp = l->head;

    while (temp != nullptr)
    {
        fout << temp->name << endl;
        fout << temp->telephone << endl;

        temp = temp->next;
    }

    fout.close();
}





















