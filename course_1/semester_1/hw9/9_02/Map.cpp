#include <iostream>
#include <fstream>
#include <cstring>

#include "Map.h"
#include "PathsArchive.h"
#include "PriorityQueue.h"

using namespace std;

enum mapElementStates
{
    freeState = 0,
    burrierState = 1,
    processedState = 2,
    visitedState = 3
};

PathsArchive *archive;
const int stepLength = 1;

MapElement *createMapElement(int passedLength, int toGoLength, int elementLine, int elementColumn, int previousLine, int previousColumn)
{
    MapElement *newElem = new MapElement;

    newElem->passedLength = passedLength;
    newElem->toGoLength = toGoLength;
    newElem->elementLine = elementLine;
    newElem->elementColumn = elementColumn;
    newElem->previousLine = previousLine;
    newElem->previousColumn = previousColumn;

    return newElem;
}

void deleteMap(int **&map, int size)
{
    for (int i = 0; i < size; i++)
        delete[] map[i];

    delete[] map;
    map = nullptr;
}

int **loadFile(const char *fileName, int &size, MapElement *&start, MapElement *&finish)
{
    ifstream fin(fileName);

    int startLine = 0;
    int startColumn = 0;
    int finishLine = 0;
    int finishColumn = 0;
    fin >> startLine >> startColumn >> finishLine >> finishColumn;

    start = createMapElement(0, -1, startLine, startColumn, startLine, startColumn);
    finish = createMapElement(-1, -1, finishLine, finishColumn, finishLine, finishColumn);

    char buffer[2048] = {'\0'};
    fin >> buffer;
    size = strlen(buffer);

    int **map = new int *[size];
    for (int i = 0; i < size; i++)
    {
        map[i] = new int[size];

        for (int j = 0; j < size; j++)
            map[i][j] = 0;
    }

    int line = 0;

    do
    {
        for (int i = 0; i < size; i++)
            map[line][i] = (buffer[i] == '0') ? freeState : burrierState;

        fin >> buffer;
        line++;
    } while(!fin.eof() && line < size);

    fin.close();
    return map;
}

int predictLengthToFinish(int line, int column, MapElement *finish)
{
    int lines = finish->elementLine - line;
    int columns = finish->elementColumn - column;

    lines = (lines > 0) ? lines : -lines;
    columns = (columns > 0) ? columns : -columns;

    return lines + columns;
}

void processNeighbor(MapElement *parent, int **map, int size, int lineOffset, int columnOffset, PriorityQueue *queue, MapElement *finish)
{
    int newLine = parent->elementLine + lineOffset;
    int newColumn = parent->elementColumn + columnOffset;

    if (newLine < 0 || newLine >= size || newColumn < 0 || newColumn >= size)
        return;

    if (map[newLine][newColumn] != freeState)
        return;

    int passedLength = parent->passedLength + stepLength;
    int toGoLength = predictLengthToFinish(newLine, newColumn, finish);

    if (newLine == finish->elementLine && newColumn == finish->elementColumn)
    {
        if (passedLength < finish->passedLength || finish->passedLength == -1)
        {
            finish->passedLength = passedLength;
            finish->previousLine = parent->elementLine;
            finish->previousColumn = parent->elementColumn;
        }

        map[newLine][newColumn] = processedState;
        return;
    }
    else
    {
        MapElement *neighbor = createMapElement(passedLength, toGoLength, newLine, newColumn, parent->elementLine, parent->elementColumn);
        insert(neighbor, queue);
        map[newLine][newColumn] = processedState;
        return;
    }
}

void processNeighbours(MapElement *toProcess, int **map, int size, PriorityQueue *queue, MapElement *finish)
{
    processNeighbor(toProcess, map, size, -1, 0, queue, finish);
    processNeighbor(toProcess, map, size, 1, 0, queue, finish);
    processNeighbor(toProcess, map, size, 0, -1, queue, finish);
    processNeighbor(toProcess, map, size, 0, 1, queue, finish);

    map[toProcess->elementLine][toProcess->elementColumn] = visitedState;
    addInArchive(toProcess, archive);
}

bool lessThenMinQueueElem(int value, PriorityQueue *queue)
{
    if (value == -1)
        return false;

    MapElement *min = extractMin(queue);

    if (min == nullptr)
        return true;

    int minQueueValue = min->passedLength + min->toGoLength;
    insert(min, queue);

    return value < minQueueValue;
}

void moveDataFromQueueToArchive(PriorityQueue *queue, PathsArchive *archive)
{
    while (!isEmpty(queue))
    {
        MapElement *pathPart = extractMin(queue);
        addInArchive(pathPart, archive);
    }
}

void drawClosestPath(int **map, int size, MapElement *start, MapElement *finish)
{
    PriorityQueue *queue = createPriorityQueue();
    archive = createArchive(); //global variable

    processNeighbours(start, map, size, queue, finish);

    while (!lessThenMinQueueElem(finish->passedLength, queue) && !isEmpty(queue))
    {
        MapElement *toProcess = extractMin(queue);
        processNeighbours(toProcess, map, size, queue, finish);
    }

    moveDataFromQueueToArchive(queue, archive);
    deletePriorityQueue(queue);
}

void printMap(int **map, int size, MapElement *finish, MapElement *start, const char *mode)
{
    if (finish->passedLength == -1)
        return;

    map[finish->elementLine][finish->elementColumn] = -3; //finish mark

    int prevLine = finish->previousLine;
    int prevColumn = finish->previousColumn;

    while (prevLine != start->elementLine || prevColumn != start->elementColumn)
    {
        map[prevLine][prevColumn] = -2; //path mark

        MapElement *previous = extractValue(prevLine, prevColumn, archive);
        prevLine = previous->previousLine;
        prevColumn = previous->previousColumn;
        delete previous;
    }

    map[start->elementLine][start->elementColumn] = -1; //start mark

    if (strcmp(mode, "debug") == 0)
    {
        while (!isEmpty(archive))
        {
            MapElement *pathPart = extractAny(archive);
            int line = pathPart->elementLine;
            int column = pathPart->elementColumn;
            int value = pathPart->passedLength + pathPart->toGoLength;

            delete pathPart;

            map[line][column] = (map[line][column] == visitedState) ? -value : value;
        }
    }

    deleteArchive(archive);

    cout << endl << "   S - start" << endl;
    cout << "   F - finish" << endl;
    cout << "   ... - path" << endl;
    cout << "   # - barrier" << endl;
    cout << "   Number - the value of the heuristic function (only \"debug\" mode)" << endl;
    cout << "   You can switch print mode between \"debug\" and \"normal\" by changing constant in main() function" << endl;

    cout << "   ";

    for (int i = 0; i < size; i++)
        cout << "___";

    cout << "_" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "  |";
        for (int j = 0; j < size; j++)
            switch (map[i][j]) {
            case -3:
                cout << " F ";
                break;
            case -2:
                cout << " . ";
                break;
            case -1:
                cout << " S ";
                break;
            case 0:
                cout << "   ";
                break;
            case 1:
                cout << " # ";
                break;
            default:
                if (strcmp(mode, "debug") == 0)
                    if (map[i][j] < 0)
                        printf(".%-2d", -map[i][j]);
                    else
                        printf(" %-2d", map[i][j]);
                else
                    cout << "   ";
                break;
            }
        cout << " |" << endl;
    }

    cout << "  |";
    for (int i = 0; i < size; i++)
        cout << "___";

    cout << "_|" << endl;
}
