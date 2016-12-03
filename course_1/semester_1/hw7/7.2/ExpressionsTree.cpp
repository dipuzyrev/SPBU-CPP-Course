#include <iostream>
#include <fstream>
#include "ExpressionsTree.h"

using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;
};

Node *createNode(int value, Node *left, Node *right)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

struct ExpressionsTree
{
    Node *root;
};

ExpressionsTree *create()
{
    ExpressionsTree *newTree = new ExpressionsTree;
    newTree->root = nullptr;
    return newTree;
}

int charToInt(char *str)
{
    int i = 0;
    int newNumber = 0;

    while (i < 1024 && (int) str[i] >= (int) '0' && (int) str[i] <= (int) '9')
    {
        newNumber = newNumber * 10 + ((int) str[i] - (int) '0');
        i++;
    }

    return newNumber;
}

int computeBufferLength(char *buffer)
{
    for (int i = 0; i < 2048; i++)
        if (buffer[i] == '\0')
            return i;
}

int defineOperation(char c)
{
    if (c == '+')
        return 1;
    else if (c == '-')
        return 2;
    else if (c == '*')
        return 3;
    else if (c == '/')
        return 4;
    else
        return -1;
}

void recursiveLoad(char *buffer, int &temp, int max, Node *parentNode, int direction)
{
    if (temp >= max)
        return;

    if (buffer[temp] == '(')
    {
        temp += 1;
        int operationToAdd = defineOperation(buffer[temp]);

        if (direction == 1)
        {
            parentNode->left = createNode(operationToAdd, nullptr, nullptr);
            temp += 2;
            recursiveLoad(buffer, temp, max, parentNode->left, 1);
            recursiveLoad(buffer, temp, max, parentNode->left, 2);
        }
        else
        {
            parentNode->right = createNode(operationToAdd, nullptr, nullptr);
            temp += 2;
            recursiveLoad(buffer, temp, max, parentNode->right, 1);
            recursiveLoad(buffer, temp, max, parentNode->right, 2);
        }
    }
    else if((int) buffer[temp] >= (int) '0' && (int) buffer[temp] <= '9')
    {
        int number = 0;

        while((int) buffer[temp] >= (int) '0' && (int) buffer[temp] <= (int) '9')
        {
            number = number * 10 + ((int) buffer[temp] - (int) '0');
            temp++;
        }

        if (direction == 1)
        {
            parentNode->left = createNode(number, nullptr, nullptr);
            temp += 1;
        }
        else
        {
            parentNode->right = createNode(number, nullptr, nullptr);
            temp += 2;
        }
    }
    else
        throw 99;
}

void loadExpressionsFromFile(char const *fileName, ExpressionsTree *t)
{
    ifstream fin(fileName);

    char buffer[2048] = {'\0'};
    fin.getline(buffer, 2048);

    int max = computeBufferLength(buffer) - 1;
    int temp = 0;

    if (max > 1 && buffer[temp] == '(')
    {
        t->root = createNode(defineOperation(buffer[1]), nullptr, nullptr);
        temp += 3;
        recursiveLoad(buffer, temp, max, t->root, 1);
        recursiveLoad(buffer, temp, max, t->root, 2);
    }

    fin.close();
}

double computeOperation(int num1, int num2, int operationCode)
{
    switch (operationCode)
    {
    case 1:
        return num1 + num2;
    case 2:
        return num1 - num2;
    case 3:
        return num1 * num2;
    case 4:
        return (double) num1 / num2;
    default:
        return 0;
        break;
    }
}

double recursiveCompute(Node *parentNode)
{
    if (parentNode == nullptr)
        return 0;

    if (parentNode->left == nullptr && parentNode->right == nullptr)
        return parentNode->value;

    int num1 = recursiveCompute(parentNode->left);
    int num2 = recursiveCompute(parentNode->right);
    return computeOperation(num1, num2, parentNode->value);
}

double compute(ExpressionsTree *expressions)
{
    return recursiveCompute(expressions->root);
}

void printOperation(int code)
{
    switch (code)
    {
    case 1:
        cout << "+";
        break;
    case 2:
        cout << "-";
        break;
    case 3:
        cout << "*";
        break;
    case 4:
        cout << "/";
        break;
    }
}

void recursivePrintNode(Node *parentNode)
{
    if (parentNode == nullptr)
        return;

    if (parentNode->left == nullptr && parentNode->right == nullptr)
        cout << parentNode->value;
    else
    {
        cout << "(";
        recursivePrintNode(parentNode->left);
        cout << " ";
        printOperation(parentNode->value);
        cout << " ";
        recursivePrintNode(parentNode->right);
        cout << ")";
        return;
    }
}

void print(ExpressionsTree *t)
{
    if (t->root == nullptr)
        return;

    Node *temp = t->root;

    if (temp->left == nullptr && temp->right == nullptr)
    {
        cout << temp->value;
        return;
    }

    cout << "(";
    recursivePrintNode(temp->left);
    cout << " ";
    printOperation(temp->value);
    cout << " ";
    recursivePrintNode(temp->right);
    cout << ")";
}

void recursiveDeleteNode(Node *n)
{
    if (n == nullptr)
        return;

    if (n->left == nullptr && n->right == nullptr)
        delete n;
    else
    {
        recursiveDeleteNode(n->left);
        recursiveDeleteNode(n->right);
        delete n;
    }
}

bool clear(ExpressionsTree *t)
{
    if (t->root == nullptr)
        return false;

    Node *temp = t->root;
    recursiveDeleteNode(temp->left);
    recursiveDeleteNode(temp->right);
    delete temp;

    t->root = nullptr;
}
