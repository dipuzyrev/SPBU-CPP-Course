#include <iostream>
#include <limits>
#include "Stack.h"

using namespace std;

int convertToNumber(char number)
{
    int result = number - 48; //ASCII codes: 48:0, 49:1, 50:2 ... 57:9
    return result;
}

int performOperation(char operation, int number1, int number2)
{
    switch (operation) {
    case '-':
        return number1 - number2;
        break;
    case '+':
        return number1 + number2;
        break;
    case '*':
        return number1 * number2;
        break;
    case '/':
        return number1 / number2;
        break;
    default:
        return INT_MIN;
    }
}

int getStrLength(char str[], int maxSize)
{
    int length = 0;
    for (int i = 0; i < maxSize; i++)
        if (str[i] != '\0')
            length++;
        else
            return length;
    return length;
}

int main()
{
    int const maxSize = 1024;
    char inputStr[maxSize] = {'\0'};
    Stack *operands = createStack();

    cout << "Enter your postfix expression: ";
    cin.getline(inputStr, maxSize);

    int length = getStrLength(inputStr, maxSize);
    for (int i = 0; i < length; i++)
    {
        char token = inputStr[i];
        if (isdigit(token))
        {
            int value = convertToNumber(token);
            push(operands, value);
        }
        else
        {
            int number1 = pop(operands);
            int number2 = pop(operands);
            int result = performOperation(token, number1, number2);
            push(operands, result);
        }
    }

    int result = pop(operands);
    cout << "Result: " << result << endl;

    return 0;
}
