#include <iostream>
#include "Stack.h"
#include "InfixToPostfix.h"

using namespace std;

int main()
{
    int const maxLength = 1024;
    char infixExpression[maxLength] = {' '};
    inputInfixExpression(infixExpression, maxLength);

    char postfixExpression[maxLength] = {' '};
    convertToPostfix(infixExpression, postfixExpression, maxLength);

    outputPostfix(postfixExpression);

    return 0;
}
