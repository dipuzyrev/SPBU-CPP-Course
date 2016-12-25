#pragma once
#include "CodesList.h"

struct Tree;

Tree *createTree(char value);
void deleteTree(Tree *&tree);

void mergeTrees(Tree *baseTree, Tree *&treeToMerge);
void fillCodesList(Tree *tree, CodesList *codes);
void printTree(const char *fileName, Tree *t);
Tree *loadTreeFromFile(const char *fileName, const int bufferSize);
