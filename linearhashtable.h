#ifndef LINEARHASHTABLE_H
#define LINEARHASHTABLE_H

#include <QString>
#include "HashTable.h"


class LinearHashTable
{
public:
    LinearHashTable(int capacity);
    void insert(int key, const QString value);
    QString get(int key);
    bool contain(int key);
    bool remove(int key);
    void print();
private:
    int capacity;
    int hash(int key);
    HashNode **nodes;
};

#endif // LINEARHASHTABLE_H
