#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    char *s = "ffffffff";

    cout << strlen(s);

    delete[] s;
    return 0;
}
