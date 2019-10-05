#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Node.h"


class BinarySearchTree
{
public:
    BinarySearchTree();
    void insert(int value);
    bool find(int value);
    int getCount();
    bool remove(int value);
    void walk();
    int min() const;
    int max() const;
    void clear();

private:
    Node* root{};
    int count = 0;
    void _walk(Node* root);
    void _clear(Node* root);
//    Node* findMinNode(int value, Node* current);
    Node* findNode(Node* current, int value);
//    int nestedMin(Node* minimal) const;
    bool removeTwo(Node *current,Node *tempNode );
};

#endif // BINARYSEARCHTREE_H
