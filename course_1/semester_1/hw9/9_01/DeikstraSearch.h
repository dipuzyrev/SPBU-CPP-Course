#pragma once
#include "CustomString.h"

struct City
{
    int pathLength;
    String *path;
    bool visited;
};

void deleteMap(int **&map, int size);
void deleteCitiesList(City **&citiesList, int citiesCount);

void runDeikstraAlgorithm(int **map, int startFrom, City **list, int size);
int **loadFile(const char *fileName, int &citiesCount, int &roadsCount);
City **createCitiesList(int citiesCount);
void printCitiesList(City **citiesList, int size);
