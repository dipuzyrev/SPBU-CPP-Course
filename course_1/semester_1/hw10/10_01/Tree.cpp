#include <iostream>
#include <fstream>

#include "Tree.h"
#include "CustomString.h"

using namespace std;

struct Node
{
    char value;
    Node *left;
    Node *right;
};

struct Tree
{
    Node *root;
};

Node *createNode(char value, Node *left, Node *right)
{
    Node *newNode = new Node;
    newNode->value = value;
    newNode->right = right;
    newNode->left = left;
    return newNode;
}

Tree *createTree(char value)
{
    Tree *newTree = new Tree;
    newTree->root = createNode(value, nullptr, nullptr);
    return newTree;
}

void deleteNode(Node *&node)
{
    if (node == nullptr)
        return;

    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}

void deleteTree(Tree *&tree)
{
    if (tree == nullptr)
        return;

    if (tree->root != nullptr)
    {
        deleteNode(tree->root->left);
        deleteNode(tree->root->right);
        delete tree->root;
    }

    delete tree;
    tree = nullptr;
}

void mergeTrees(Tree *baseTree, Tree *&treeToMerge)
{
    Node *root = createNode('\0', baseTree->root, treeToMerge->root);

    baseTree->root = root;

    delete treeToMerge;
    treeToMerge = nullptr;
}

void fillCodesList(Node *node, String *previousCode, CodesList *codes)
{
    if (node == nullptr)
    {
        deleteString(previousCode);
        return;
    }

    if (node->left == nullptr && node->right == nullptr)
        addToCodesList(node->value, previousCode, codes);
    else
    {
        String *leftCode = createConcat(previousCode, "0");
        String *rightCode = createConcat(previousCode, "1");

        fillCodesList(node->left, leftCode, codes);
        fillCodesList(node->right, rightCode, codes);

        deleteString(previousCode);
    }
}

void fillCodesList(Tree *tree, CodesList *codes)
{
    String *leftCode = createString("0");
    String *rightCode = createString("1");

    fillCodesList(tree->root->left, leftCode, codes);
    fillCodesList(tree->root->right, rightCode, codes);
}

void printNode(ostream &fout, Node *parentNode)
{
    if (parentNode == nullptr)
        return;

    if (parentNode->left == nullptr && parentNode->right == nullptr)
    {
        if (parentNode->value == '\n')
            fout << " \\n";
        else
            fout << " " << parentNode->value;
    }
    else
    {
        if (parentNode->value == '\0')
            fout << " (null";
        else
            fout << " (" << parentNode->value;

        printNode(fout, parentNode->left);
        printNode(fout, parentNode->right);
        fout << ")";
    }
}

void printTree(const char *fileName, Tree *t)
{
    ofstream fout(fileName);

    if (t->root == nullptr)
        return;

    Node *temp = t->root;

    if (temp->value == '\0')
        fout << "(null";
    else
        fout << "(" << temp->value;

    printNode(fout, temp->left);
    printNode(fout, temp->right);
    fout << ")" << endl;

    fout.close();
}
