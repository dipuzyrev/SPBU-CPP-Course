#include <iostream>
#include <fstream>

#include "DeikstraSearch.h"
#include "PriorityQueue.h"
#include "CustomString.h"

using namespace std;

enum pathLength
{
    infinityLength = -1
};

void deleteMap(int **&map, int size)
{
    for (int i = 0; i < size; i++)
        delete[] map[i];

    delete[] map;
    map = nullptr;
}

void deleteCitiesList(City **&citiesList, int citiesCount)
{
    for (int i = 0; i < citiesCount; i++)
    {
        if (citiesList[i] != nullptr)
        {
            deleteString(citiesList[i]->path);
            delete citiesList[i];
        }
    }

    delete citiesList;
    citiesList = nullptr;
}

int **loadFile(const char *fileName, int &citiesCount, int &roadsCount)
{
    ifstream fin(fileName);

    fin >> citiesCount;
    fin >> roadsCount;

    int **map = new int *[citiesCount];
    for (int i = 0; i < citiesCount; i++)
    {
        map[i] = new int[citiesCount];

        for (int j = 0; j < citiesCount; j++)
            map[i][j] = 0;
    }

    while (!fin.eof())
    {
        int city1 = 0;
        int city2 = 0;
        int roadLength = 0;
        fin >> city1 >> city2 >> roadLength;

        map[city1 - 1][city2 - 1] = roadLength;
        map[city2 - 1][city1 - 1] = roadLength;
    }

    fin.close();
    return map;
}

City **createCitiesList(int citiesCount)
{
    City **citiesList = new City* [citiesCount];

    for (int i = 0; i < citiesCount; i++)
    {
        citiesList[i] = new City;
        citiesList[i]->path = nullptr;
        citiesList[i]->pathLength = infinityLength;
        citiesList[i]->visited = false;
    }

    return citiesList;
}

void updateCity(int index, int pathLen, String *path, bool visited, City **list)
{
    City *city = list[index];

    if (!city->visited)
    {
        city->path = path;
        city->pathLength = pathLen;
        city->visited = visited;
    }
}

void updateNeighbors(int **map, int size, int index, City **list, PriorityQueue *queue)
{
    int *city = map[index];

    for (int i = 0; i < size; i++)
    {
        int pathLen = list[index]->pathLength + city[i];

        if (city[i] != 0 && !list[i]->visited && (list[i]->pathLength == infinityLength || pathLen < list[i]->pathLength))
        {
            int pathLen = list[index]->pathLength + city[i];

            String *path = createString();
            String *neighborNumber = createString(i + 1);
            String *delimeter = createString("-");
            concat(path, list[index]->path);
            concat(path, delimeter);
            concat(path, neighborNumber);

            updateCity(i, pathLen, path, false, list);
            insert(pathLen, i + 1, queue);

            deleteString(neighborNumber);
            deleteString(delimeter);
        }
    }
}

void markAsVisited(int index, City **list)
{
    list[index]->visited = true;
}

void runDeikstraAlgorithm(int **map, int startFrom, City **list, int size)
{
    PriorityQueue *queue = createPriorityQueue();
    String *startPath = createString(startFrom + 1);

    updateCity(startFrom, 0, startPath, false, list);
    updateNeighbors(map, size, startFrom, list, queue);
    markAsVisited(startFrom, list);

    while (!isEmpty(queue))
    {
        QueueElement *closestCity = extractMin(queue);
        updateNeighbors(map, size, closestCity->value - 1, list, queue);
        markAsVisited(closestCity->value - 1, list);
    }

    deletePriorityQueue(queue);
}

void printCitiesList(City **citiesList, int size)
{
    int min = infinityLength;
    int minIndex = 0;
    bool empty = false;

    while (!empty)
    {
        empty = true;

        for (int i = 0; i < size; i++)
            if (citiesList[i] != nullptr)
            {
                empty = false;

                if (citiesList[i]->pathLength <= min || min == infinityLength)
                {
                    min = citiesList[i]->pathLength;
                    minIndex = i;
                }
            }

        if (min != infinityLength)
        {
            City *city = citiesList[minIndex];
            cout << "City " << minIndex + 1 << ": distance - " << city->pathLength << " / path - " << getChars(city->path) << endl;

            deleteString(city->path);
            delete city;
            citiesList[minIndex] = nullptr;
        }
        min = infinityLength;
    }
}
