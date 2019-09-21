#include "binarysearchtree.h"
//#include "Node.h"
#include <QDebug>

BinarySearchTree::BinarySearchTree()
{

}

void BinarySearchTree::insert(int value)
{
    bool finded = false;

    if(!this->root) {
        Node* temp = new Node();
        temp->key = value;
        temp->left = nullptr;
        temp->right = nullptr;
        this->root = temp;
        this->count++;
    } else {
        Node* tempNode = this->root;
        while(!finded) {
            if( value < tempNode->key ) {
               if(!tempNode->left) {
                   tempNode->left = new Node();
                   tempNode->left->key = value;
                   this->count++;
                   return;
               } else {
                 tempNode = tempNode->left;
               }

            } else {
                if( value > tempNode->key ) {
                    if(!tempNode->right) {

                        tempNode->right = new Node();
                        tempNode->right->key = value;
                        this->count++;
                        return;
                    } else {
                        tempNode = tempNode->right;
                    }
                }
            }
        }
    }
}

bool BinarySearchTree::find(int value)
{
    bool finded = false;

    Node* tempNode = this->root;
    while(!finded) {
        if(tempNode == nullptr) {
            return false;
        }
        if( value <= tempNode->key ) {
           if(tempNode && tempNode->key == value) {
               return true;
           } else {
             tempNode = tempNode->left;
           }

        } else {
            if( value >= tempNode->key ) {
                if(tempNode && tempNode->key == value) {
                    return true;
                } else {
                    tempNode = tempNode->right;
                }
            }
        }
    }
    return false;
}

