#include "PathsArchive.h"

struct ArchiveElement
{
    MapElement *value;
    ArchiveElement *next;
};

struct PathsArchive
{
    ArchiveElement *head;
    int size;
};

ArchiveElement *createElement(MapElement *value, ArchiveElement *next)
{
    ArchiveElement *newElem = new ArchiveElement;
    newElem->next = next;
    newElem->value = value;

    return newElem;
}

PathsArchive *createArchive()
{
    PathsArchive *newArchive = new PathsArchive;
    newArchive->head = nullptr;
    newArchive->size = 0;
    return newArchive;
}

void deleteArchive(PathsArchive *&archive)
{
    if (archive == nullptr)
        return;

    if (!isEmpty(archive))
    {
        ArchiveElement *temp = archive->head;

        while (temp != nullptr)
        {
            ArchiveElement *toDelete = temp;
            temp = temp->next;
            delete toDelete->value;
            delete toDelete;
        }
    }

    delete archive;
    archive = nullptr;
}

bool isEmpty(PathsArchive *archive)
{
    return archive->size == 0;
}

void addInArchive(MapElement *value, PathsArchive *archive)
{
    ArchiveElement *newElement = createElement(value, archive->head);
    archive->head = newElement;
    archive->size++;
}

MapElement *extractValue(int elementLine, int elementColumn, PathsArchive *archive)
{
    if (isEmpty(archive))
        return nullptr;

    if (archive->head->value->elementLine == elementLine && archive->head->value->elementColumn == elementColumn)
    {
        MapElement *toReturn = archive->head->value;
        ArchiveElement *toDelete = archive->head;
        archive->head = archive->head->next;
        delete toDelete;
        archive->size--;
        return toReturn;
    }

    ArchiveElement *temp = archive->head;
    MapElement *toReturn = nullptr;

    if (temp->next->next == nullptr)
        return nullptr;

    while (temp->next != nullptr)
    {
        if (temp->next->value->elementLine == elementLine && temp->next->value->elementColumn == elementColumn)
        {
            toReturn = temp->next->value;
            ArchiveElement *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            archive->size--;
            return toReturn;
        }
        temp = temp->next;
    }

    return nullptr;
}

MapElement *extractAny(PathsArchive *archive)
{
    if (isEmpty(archive))
        return nullptr;

    MapElement *toReturn = archive->head->value;
    ArchiveElement *toDelete = archive->head;
    archive->head = archive->head->next;
    delete toDelete;

    archive->size--;
    return toReturn;
}
