#include <iostream>

using namespace std;

int inputN()
{
    int n = 0;
    printf("Input (n): ");
    scanf("%i", &n);
    return n;
}

//1 - right, 2 - bottom, 3 - left, 4 - top
int defineEdge(int n, int cover, int row, int column, int **arrPrinted)
{
    if ((column - 1 >= 0) && (row + 1 < n))
        if ((arrPrinted[row][column - 1] == 1) && (arrPrinted[row + 1][column] == 0))
            return 1;

    if ((row - 1 >= 0) && (column - 1 >= 0))
        if ((arrPrinted[row - 1][column] == 1) && (arrPrinted[row][column - 1] == 0))
            return 2;

    if ((column + 1 < n) && (row - 1 >= 0))
        if ((arrPrinted[row][column + 1] == 1) && (arrPrinted[row - 1][column] == 0))
            return 3;

    if ((row + 1 < n) && (column + 1 < n))
        if ((arrPrinted[row + 1][column] == 1) && (arrPrinted[row][column + 1] == 0))
            return 4;
}

int main()
{
    //Array printing algorithm:
    //25 10 11 12 13
    //24 09 02 03 14
    //23 08 01 04 15
    //22 07 06 05 16
    //21 20 19 18 17

    int n = inputN();

    int **arr = new int *[n];
    int **arrPrinted = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        arrPrinted[i] = new int[n];
    }
    for (int row = 0; row < n; row++)
        for (int column = 0; column < n; column++)
        {
            arr[row][column] = (row + 1) * 10 + column + 1;
            arrPrinted[row][column] = 0; //0 - not printed, 1 - printed
        }

    //Printing array for checking
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n; column++)
            cout << arr[row][column] << "   ";
        cout << endl;
    }
    cout << endl;

    int currentIndex[2] = {n / 2, n / 2};
    int currentCover = n / 2 + 1;
    printf("%i, ", arr[currentIndex[0]][currentIndex[1]]);
    arrPrinted[currentIndex[0]][currentIndex[1]] = 1;

    currentCover -= 1;
    currentIndex[0] -= 1;
    currentIndex[1] = n / 2;

    while (currentCover > 0)
    {
        int row = currentIndex[0];
        int column = currentIndex[1];
        printf("%i, ", arr[row][column]);
        arrPrinted[row][column] = 1;

        //check if it is last element in current cover (top left corner)
        if ((row == currentCover - 1) && (column == currentCover - 1))
        {
            currentCover -= 1;
            currentIndex[0] = row - 1;
            continue;
        }

        int edge = defineEdge(n, currentCover, row, column, arrPrinted);
        switch (edge) {
        case 1:
            currentIndex[0] = row + 1;
            currentIndex[1] = column;
            break;
        case 2:
            currentIndex[0] = row;
            currentIndex[1] = column - 1;
            break;
        case 3:
            currentIndex[0] = row - 1;
            currentIndex[1] = column;
            break;
        case 4:
            currentIndex[0] = row;
            currentIndex[1] = column + 1;
            break;
        default:
            break;
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
        delete[] arrPrinted[i];
    }
    return 0;
}