#include <iostream>
#include <fstream>
#include "ExpressionsTree.h"

using namespace std;

int main()
{
    char const *fileName = "input.txt";
    ExpressionsTree *expressions = create();

    loadExpressionsFromFile(fileName, expressions);
    print(expressions);
    double result = compute(expressions);

    cout << endl << "Expression value: " << result << endl;

    clear(expressions);
    delete expressions;
    delete[] fileName;

    return 0;
}
