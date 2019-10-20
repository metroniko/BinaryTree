#ifndef RANDOMBST_H
#define RANDOMBST_H
#include "Node.h"


class RandomBST
{
public:
    RandomBST();
    void insert (int key);
    void remove(int value);
    bool find(int value);
    void walk();
    void clear();
    int min() const;
    int max() const;

private:
    Node* root{nullptr};
    Node* insertIn(Node* node, int key);
    Node* insertAsRoot(Node* node, int key);
    Node* rotateLeft(Node* node);
    Node* rotateRight(Node* node);
    void fixsize(Node* node);
    int getSize(Node* node);
    Node* findNode(Node* current, int value);
    void _walk(Node* root);
    void _clear(Node* root);
    Node* _remove(Node* root, int value);

    Node* _join(Node* left, Node* right);

};

#endif // RANDOMBST_H
