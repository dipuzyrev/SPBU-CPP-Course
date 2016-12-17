#include <iostream>
#include "DeikstraSearch.h"

using namespace std;

int main()
{
    const char *inputFile = "input.txt";
    const int startCity = 1;

    int citiesCount = 0;
    int roadsCount = 0;
    int **map = loadFile(inputFile, citiesCount, roadsCount);

    City **citiesList = createCitiesList(citiesCount);

    runDeikstraAlgorithm(map, startCity - 1, citiesList, citiesCount);
    printCitiesList(citiesList, citiesCount);
    cout << endl;

    deleteMap(map, citiesCount);
    deleteCitiesList(citiesList, citiesCount);

    return 0;
}
