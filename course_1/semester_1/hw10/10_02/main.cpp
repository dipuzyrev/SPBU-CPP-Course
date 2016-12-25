#include <iostream>
#include <fstream>
#include <cstring>

#include "CodesList.h"
#include "Tree.h"

using namespace std;

const int bufferSize = 2048;

void decodeFile(const char *inputFile, const char *outputFile, CodesList *codesList)
{
    ifstream fin(inputFile);
    ofstream fout(outputFile);

    char buffer[bufferSize] = {'\0'};
    fin.getline(buffer, bufferSize);
    fin >> buffer;

    int i = 0;
    while(!fin.eof())
    {
        String *code = createString(buffer);
        char value = getValue(code, codesList);

        fout << value;

        deleteString(code);

        fin >> buffer;
        i++;
    }

    fout.close();
    fin.close();
}

int main()
{
    const char *inputFile = "input.txt";
    const char *outputFile = "output.txt";

    Tree *charsTree = loadTreeFromFile(inputFile, bufferSize);

    CodesList *codesList = createCodesList();
    fillCodesList(charsTree, codesList);

    decodeFile(inputFile, outputFile, codesList);

    deleteTree(charsTree);
    deleteCodesList(codesList);

    return 0;
}
