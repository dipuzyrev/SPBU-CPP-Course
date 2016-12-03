#include <iostream>
#include <fstream>
#include "List.h"

using namespace std;

struct ListItem
{
    ListItem *next;
    char s;
    int value;
};

struct List
{
    ListItem *head;
    int size;
};

ListItem *createListItem(char s, ListItem *next)
{
    ListItem *newItem = new ListItem;
    newItem->next = next;
    newItem->s = s;
    newItem->value = 1;
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

void addValue(List *l, char character)
{
    if (isEmpty(l))
    {
        ListItem *newItem = createListItem(character, nullptr);
        l->head = newItem;
        l->size = 1;
        return;
    }

    ListItem *temp = l->head;

    while (temp->next != nullptr && temp->s != character)
        temp = temp->next;

    if (temp->s == character)
        temp->value++;
    else
    {
        temp->next = createListItem(character, nullptr);
        l->size++;
    }

    return;
}

void printList(List *l, char const *fileName)
{
    if (isEmpty(l))
        return;

    ofstream fout(fileName);

    while (!isEmpty(l))
    {
        ListItem *temp = l->head;

        int maxValue = temp->value;
        ListItem *maxItem = temp;

        if (temp->next == nullptr)
        {
            fout << temp->s << " -- " << temp->value << endl;
            deleteMax(l);
            return;
        }

        while(temp->next != nullptr)
        {
            if (temp->next->value > maxValue)
            {
                maxValue = temp->next->value;
                maxItem = temp->next;
            }

            temp = temp->next;
        }

        fout << maxItem->s << " -- " << maxItem->value << endl;
        deleteMax(l);
    }


    fout.close();
}

void deleteMax(List *l)
{
    if (isEmpty(l))
        return;

    ListItem *temp = l->head;

    if (temp->next == nullptr)
    {
        delete l->head;
        l->head = nullptr;
        l->size = 0;
        return;
    }

    int maxValue = l->head->value;
    ListItem *beforeMaxItem = createListItem('a', l->head);

    while(temp->next != nullptr)
    {
        if (temp->next->value > maxValue)
        {
            maxValue = temp->next->value;
            beforeMaxItem = temp;
        }

        temp = temp->next;
    }

    ListItem *toDelete = beforeMaxItem->next;
    beforeMaxItem->next = beforeMaxItem->next->next;

    toDelete->value = 0;
    if (l->head->value == 0)
        l->head = l->head->next;

    delete toDelete;
    l->size--;
}

bool clearList(List *l)
{
    if (isEmpty(l))
        return false;

    ListItem *toDelete = l->head;

    while (toDelete != nullptr)
    {
        l->head = toDelete->next;
        delete toDelete;
        toDelete = l->head;
    }

    l->size = 0;
    return true;
}
