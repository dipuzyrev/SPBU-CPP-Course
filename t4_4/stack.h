#pragma once

struct Stack;

Stack *createStack();
void push(Stack *s, char value);
char pop(Stack *s);
char top(Stack *s);
bool isEmpty(Stack const *s);
