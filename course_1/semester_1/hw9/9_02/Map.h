#pragma once

struct MapElement
{
    int passedLength;
    int toGoLength;
    int elementLine;
    int elementColumn;
    int previousLine;
    int previousColumn;
};

MapElement *createMapElement(int passedLength, int toGoLength, int elementLine, int elementColumn, int previousLine, int previousColumn);
void deleteMap(int **&map, int size);

int **loadFile(const char *fileName, int &size, MapElement *&start, MapElement *&finish);
void drawClosestPath(int **map, int size, MapElement *start, MapElement *finish);
void printMap(int **map, int size, MapElement *finish, MapElement *start, const char *mode);
