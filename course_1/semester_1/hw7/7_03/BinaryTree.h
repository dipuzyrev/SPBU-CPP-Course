#pragma once

struct BinaryTree;

enum PrintMode
{
    inAscending,
    inDescending,
    structure
};

BinaryTree *create();

void addValue(int value, BinaryTree *t);
void deleteValue(int value, BinaryTree *t);
bool contains(int value, BinaryTree *t);

void print(PrintMode mode, BinaryTree *t);

void deleteTree(BinaryTree *&t);

