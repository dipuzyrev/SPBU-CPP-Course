#include <iostream>
#include <fstream>
#include <cstring>

#include "CodesList.h"
#include "Tree.h"

using namespace std;

void decodeFile(const char *inputFile, const char *outputFile, CodesList *codesList)
{
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    char buffer[1024] = {'\0'};
    fin.getline(buffer, 1024);
    fin >> buffer;

    while(!fin.eof())
    {
        String *code = createString(buffer);
        char value = getValue(code, codesList);
        fout << value;
        deleteString(code);

        fin >> buffer;
    }

    fout.close();
    fin.close();
}

int main()
{
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    Tree *charsTree = loadTreeFromFile(inputFile);

    CodesList *codesList = createCodesList();
    fillCodesList(charsTree, codesList);

    decodeFile(inputFile, outputFile, codesList);

    deleteTree(charsTree);
    deleteCodesList(codesList);

    return 0;
}
