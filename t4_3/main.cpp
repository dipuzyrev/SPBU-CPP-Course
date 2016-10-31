#include <iostream>
#include "Stack.h"

using namespace std;

int getStrLength(char str[], int maxLength)
{
    int length = 0;
    for (int i = 0; i < maxLength; i++)
        if (str[i] != '\0')
            length++;
        else
            return length;
    return length;
}

void concatStr(char str1[], char str2[], int maxLength)
{
    int length1 = getStrLength(str1, maxLength);
    int length2 = getStrLength(str2, maxLength);
    int i = length1;
    int j = 0;

    while (i < maxLength && j < length2)
    {
        str1[i] = str2[j];
        i++;
        j++;
    }
}

void concatChar(char str1[], char charToConcat, int maxStrLength)
{
    int strLength = getStrLength(str1, maxStrLength);
    if (strLength != maxStrLength)
        str1[strLength] = charToConcat;
}

bool mustPop(char token, char topOperator)
{
    if (token == ')')
        return true;

    if (token == '-' || token == '+')
        if (topOperator == '+' || topOperator == '-' || topOperator == '*' || topOperator == '/')
            return true;

    if (token == '*' || token == '/')
        if (topOperator == '*' || topOperator == '/')
            return true;

    return false;
}

void handleToken(char token, Stack *operators, char postfixExpression[], int maxLength)
{

    if (isdigit(token))
    {

        concatChar(postfixExpression, token, maxLength);
        return;
    }

    if (isEmpty(operators) || !mustPop(token, top(operators)))
    {
        push(operators, token);
        return;
    }

    char currentToken = token;
    while(!isEmpty(operators) && mustPop(currentToken, top(operators)) && top(operators) != '(')
    {
        concatChar(postfixExpression, top(operators), maxLength);
        currentToken = pop(operators);
    }
    if (top(operators) == '(')
        pop(operators);
    if (token != ')')
        push(operators, token);
}

void addRestOperators(Stack *operators, char postfixExpression[], int maxLength)
{
    while (!isEmpty(operators))
    {
        char newOperator = pop(operators);
        concatChar(postfixExpression, newOperator, maxLength);
    }
}

int main()
{
    //input expression
    cout << "Input your expression in infix notation: ";
    int const maxLength = 1024;
    char infixExpression[maxLength] = {' '};
    cin.getline(infixExpression, maxLength);

    //create empty result str
    char postfixExpression[maxLength] = {' '};

    //cyrcle: handle tokens, concat to result str (if need)
    Stack *operators = createStack();
    int infixLength = getStrLength(infixExpression, maxLength);
    for (int i = 0; i < infixLength; i++)
    {
        char currentTocken = infixExpression[i];
        handleToken(currentTocken, operators, postfixExpression, maxLength);
    }

    //get all rest of operators in stack and concat to result str
    addRestOperators(operators, postfixExpression, maxLength);

    //output result
    cout << "It is your expression if postfix notation: " << postfixExpression << endl;

    return 0;
}
