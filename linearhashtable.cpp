#include "linearhashtable.h"
#include <HashTable.h>
#include <QString>
#include <QDebug>

LinearHashTable::LinearHashTable(int capacity)
{
   this->capacity = capacity;
   this->nodes = new HashNode*[capacity];
   for(int i = 0; i< capacity; i++) {
       this->nodes[i] = nullptr;
   }
}

void LinearHashTable::insert(int key, const QString value)
{
    HashNode* tempNode = new HashNode;
    tempNode->key = key;
    tempNode->value = value;
    int indexOfHash = this->hash(tempNode->key);
    while(this->nodes[indexOfHash] && this->nodes[indexOfHash]->key != -1) {
        indexOfHash = hash(indexOfHash);
        indexOfHash++;
    }
    this->nodes[indexOfHash] = tempNode;


}

QString LinearHashTable::get(int key)
{
    int indexOfHash = this->hash(key);
    int iterator = 0;

    while(iterator < this->capacity) {
        if(this->nodes[indexOfHash] && this->nodes[indexOfHash]->key == key) {
            return this->nodes[indexOfHash]->value;
        } else {
            indexOfHash = hash(indexOfHash);
            indexOfHash++;
            iterator++;
        }
    }

    return "nothing";
}

bool LinearHashTable::contain(int key)
{
    int indexOfHash = this->hash(key);
    int iterator = 1;
    while(iterator != this->capacity) {
        if(this->nodes[indexOfHash] && this->nodes[indexOfHash]->key == key) {
            return true;
        } else {
            indexOfHash = hash(indexOfHash);
            indexOfHash++;
            iterator++;
        }
    }

    return false;
}

bool LinearHashTable::remove(int key)
{
    int indexOfHash = this->hash(key);
    HashNode* marker = new HashNode;
    marker->key = -1;
    marker->value = "";

    while(this->nodes[indexOfHash] && this->nodes[indexOfHash]->key != key) {
        indexOfHash = hash(indexOfHash);
        indexOfHash++;
    }
    this->nodes[indexOfHash] = marker;

    return true;

}

void LinearHashTable::print()
{
    for(int i = 0; i < this->capacity; i++ ) {
       if(this->nodes[i] && this->nodes[i]->key != -1)  {
           qDebug()<<this->nodes[i]->key;
       }
    }
}

int LinearHashTable::hash(int key)
{
    return key % capacity;
}
