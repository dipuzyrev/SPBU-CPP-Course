#include <iostream>
#include <fstream>
#include "ExpressionsTree.h"

using namespace std;

int main()
{
    const char *fileName = "input.txt";
    const int bufferSize = 1024;

    ExpressionsTree *expressions = create();

    loadExpressionsFromFile(fileName, expressions, bufferSize);
    print(expressions);
    double result = compute(expressions);

    cout << endl << "Expression value: " << result << endl;

    deleteTree(expressions);
    return 0;
}
