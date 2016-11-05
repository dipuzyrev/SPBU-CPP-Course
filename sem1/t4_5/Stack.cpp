#include <iostream>
#include "Stack.h"

struct StackElement
{
    StackElement *next;
    char value;
};

struct Stack
{
    StackElement *top;
    int size;
};


Stack *createStack()
{
    Stack *newStack = new Stack;
    newStack->top = nullptr;
    newStack->size = 0;
    return newStack;
}

void push(Stack *s, char value)
{
    StackElement *elem = new StackElement;
    elem->next = s->top;
    elem->value = value;
    s->top = elem;
    s->size++;
}

bool isEmpty(Stack const *s)
{
    return s->size == 0;
}

char pop(Stack *s)
{
    if (isEmpty(s))
        return 'e';

    char value = s->top->value;

    StackElement *toDelete = s->top;
    s->top = s->top->next;
    s->size--;
    delete toDelete;

    return value;
}

char top(Stack *s)
{
    if (isEmpty(s))
        return 'e';
    else
        return s->top->value;
}

void clearStack(Stack *s)
{
    if (isEmpty(s))
        return;

    StackElement *temp = s->top;
    s->top = nullptr;
    s->size = 0;

    while (temp->next != nullptr)
    {
        StackElement *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }

    delete temp;
}
