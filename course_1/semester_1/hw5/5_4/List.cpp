#include <iostream>
#include <fstream>
#include "List.h"

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

char *createStr(int length)
{
    char *str = new char[length];

    for (int i = 0; i < length; i++)
        str[i] = '\0';
    return str;
}

ListItem *createListItem(char *name, char *telephone, ListItem *next)
{
    ListItem *newItem = new ListItem;
    newItem->next = next;

    char *newName = createStr(64);
    char *newTelephone = createStr(64);

    for (int i = 0; i < 64; i++)
    {
        newName[i] = name[i];
        newTelephone[i] = telephone[i];
    }

    newItem->name = newName;
    newItem->telephone = newTelephone;
    return newItem;
}
List *createList()
{
    List *newList = new List;
    newList->head = nullptr;
    newList->size = 0;
    return newList;
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

bool addValue(List *l, char *name, char *telephone)
{
    if (isEmpty(l))
    {
        ListItem *newItem = createListItem(name, telephone, nullptr);
        l->head = newItem;
        l->size++;
        return true;
    }

    ListItem *temp = l->head;

    while (!compareCharacters(temp->telephone, telephone) && temp->next != nullptr)
        temp = temp->next;

    if (compareCharacters(temp->telephone, telephone))
        return false;
    else
    {
        ListItem *newItem = createListItem(name, telephone, nullptr);
        temp->next = newItem;
        l->size++;
        return true;
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

char *getHeadName(List *l)
{
    if (isEmpty(l))
        return '\0';
    else
        return l->head->name;
}

char *getHeadTelephone(List *l)
{
    if (isEmpty(l))
        return '\0';
    else
        return l->head->telephone;
}

void deleteHead(List *l)
{
    if (!isEmpty(l))
    {
        ListItem *toDelete = l->head;
        l->head = l->head->next;
        l->size--;
        delete toDelete;
    }
}

void clearList(List *l)
{
    if (isEmpty(l))
        return;

    ListItem *temp = l->head;

    while (temp->next != nullptr)
    {
        ListItem *toDelete = temp;
        temp = temp->next;
        delete toDelete->name;
        delete toDelete->telephone;
        delete toDelete;
    }
}
