#include "CodesList.h"
#include "CustomString.h"

struct ListElement
{
    char value;
    String *code;
    ListElement *next;
};

struct CodesList
{
    ListElement *head;
    int size;
};

ListElement *createListElement(char value, String *code, ListElement *next)
{
    ListElement *newElement = new ListElement;
    newElement->value = value;
    newElement->code = code;
    newElement->next = next;
    return newElement;
}

CodesList *createCodesList()
{
    CodesList *newList = new CodesList;
    newList->head = nullptr;
    newList->size = 0;
    return newList;
}

bool isEmpty(CodesList *list)
{
    return list->size == 0;
}

void deleteCodesList(CodesList *&list)
{
    if (!isEmpty(list))
    {
        ListElement *temp = list->head;

        while (temp != nullptr)
        {
            ListElement *toDelete = temp;
            temp = temp->next;
            deleteString(toDelete->code);
            delete toDelete;
        }
    }

    delete list;
    list = nullptr;
}

void addToCodesList(char value, String *code, CodesList *list)
{
    ListElement *newElement = createListElement(value, code, list->head);
    list->head = newElement;
    list->size++;
}

String *getCode(char value, CodesList *list)
{
    if (isEmpty(list))
        return nullptr;

    ListElement *temp = list->head;

    while (temp != nullptr && value != temp->value)
        temp = temp->next;

    if (value == temp->value)
        return temp->code;
    else
        return nullptr;
}

char getValue(String *code, CodesList *list)
{
    if (isEmpty(list))
        return '\0';

    ListElement *temp = list->head;

    while (temp != nullptr && !equals(code, temp->code))
        temp = temp->next;

    if (equals(code, temp->code))
        return temp->value;
    else
        return '\0';
}
