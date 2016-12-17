#include "Map.h"
#include "PathsArchive.h"
#include "PriorityQueue.h"

int main()
{
    const char *inputFile = "input.txt";
    const char *printMode = "debug"; //or normal

    MapElement *start;
    MapElement *finish;
    int size = 0;

    int **map = loadFile(inputFile, size, start, finish);

    drawClosestPath(map, size, start, finish);
    printMap(map, size, finish, start, printMode);

    deleteMap(map, size);
    delete start;
    delete finish;

    return 0;
}
