#pragma once
#include "Map.h"

struct PathsArchive;

PathsArchive *createArchive();
void deleteArchive(PathsArchive *&archive);

void addInArchive(MapElement *value, PathsArchive *archive);
bool isEmpty(PathsArchive *archive);
MapElement *extractValue(int elementLine, int elementColumn, PathsArchive *archive);
MapElement *extractAny(PathsArchive *archive);
