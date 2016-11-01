#include <iostream>

using namespace std;

struct ListItem
{
    ListItem *next;
    int value;
};

struct List
{
    ListItem *head;
    int size;
};

ListItem *createListItem(int value, ListItem *next)
{
    ListItem *newItem = new ListItem;
    newItem->next = next;
    newItem->value = value;
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

//addValue:
//returns 0 - value added, 1 - value alredy in the list
int addValue(List *l, int value)
{
    if (isEmpty(l))
    {
        l->head = createListItem(value, nullptr);
        l->size++;
        return 0;
    }

    if (l->head->value > value)
    {
        l->head = createListItem(value, l->head);
        l->size++;
        return 0;
    }

    if (l->head->next == nullptr)
    {
        if (l->head->value == value)
            return 1;
        else if (l->head->value < value)
            l->head->next = createListItem(value, nullptr);
        else
            l->head = createListItem(value, l->head);

        l->size++;
        return 0;
    }

    ListItem *temp = l->head;
    while (temp->next->next != nullptr && temp->next->value < value)
        temp = temp->next;

    if (temp->next->next == nullptr)
    {
        if (temp->next->value == value)
            return 1;
        else
        {
            if (temp->next->value < value)
                temp->next->next = createListItem(value, nullptr);
            else if (temp->next->value > value)
                temp->next = createListItem(value, temp->next);

            l->size++;
            return 0;
        }
    }
    else if (temp->next->value == value)
        return 1;
    else
    {
        temp->next = createListItem(value, temp->next);
        l->size++;
        return 0;
    }
}


//removeValue:
//returns 0 - value removed, 1 - value isn't in the list, 2 - list empty
int removeValue(List *l, int value)
{
    if (isEmpty(l))
        return 2;

    if (l->head->next == nullptr)
    {
        if (l->head->value == value)
        {
            ListItem *toDelete = l->head;
            l->head = nullptr;
            delete toDelete;
            l->size--;
            return 0;
        }
        else
            return 1;
    }

    ListItem *temp = l->head;

    while (temp->next->next != nullptr && temp->next->value < value)
        temp = temp->next;

    if (temp->value == value)
    {
        ListItem *toDelete = l->head;
        l->head = toDelete->next;
        delete toDelete;
    }
    else if ((temp->next->next == nullptr) || (temp->next->value == value))
    {
        ListItem *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    l->size--;
    return 0;
}

void printList(List *l)
{
    if (isEmpty(l))
        return;

    ListItem *temp = l->head;
    int i = 1;

    while (temp != nullptr)
    {
        cout << i << ") " << temp->value << endl;
        i++;
        temp = temp->next;
    }
}

//clearList:
//returns 0 - list saccessfully cleared, 1 - list empty
int clearList(List *l)
{
    if (isEmpty(l))
        return 1;

    ListItem *toDelete = l->head;

    while (toDelete != nullptr)
    {
        l->head = toDelete->next;
        delete toDelete;
        toDelete = l->head;
    }

    l->size = 0;
    return 0;
}
