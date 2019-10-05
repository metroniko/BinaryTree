#include "binarysearchtree.h"
//#include "Node.h"
#include <QDebug>

BinarySearchTree::BinarySearchTree()
{

}

void BinarySearchTree::insert(int value)
{
    bool finded = false;
    Node* temp = new Node(value);
    this->count++;

    if(!this->root) {
        this->root = temp;
    } else {
        Node* tempNode = this->root;
        while(!finded) {
            if( value < tempNode->key ) {
               if(!tempNode->left) {
                   tempNode->left = temp;
                   return;
               } else {
                 tempNode = tempNode->left;
               }

            } else {
                if( value > tempNode->key ) {
                    if(!tempNode->right) {
                        tempNode->right = temp;

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
    return (findNode(this->root, value)? true: false);
}
Node *BinarySearchTree::findNode(Node *current,int value)// nested find
{
    bool finded = false;

    Node* tempNode = current;
    while(!finded) {
        if(tempNode == nullptr) {
            return nullptr;
        }
        if( value <= tempNode->key ) {
           if(tempNode && tempNode->key == value) {
               return tempNode;
           } else {
             tempNode = tempNode->left;
           }

        } else {
            if( value >= tempNode->key ) {
                if(tempNode && tempNode->key == value) {
                    return tempNode;
                } else {
                    tempNode = tempNode->right;
                }
            }
        }
    }
    return nullptr;
}

bool BinarySearchTree::removeTwo(Node *current, Node *tempNode)
{
    //найдём минимальный элемент
   //Node* minimal = (findMinNode(nestedMin(current->right), current->right));
    tempNode = current;
    current = current->right;
    Node* minimalCurrent = current;
    while(minimalCurrent != nullptr && minimalCurrent->left ) {
        current = minimalCurrent;
        minimalCurrent = minimalCurrent->left;
    }
    if(minimalCurrent && minimalCurrent->right) {
        Node* localMinimal = minimalCurrent->right;
        while(localMinimal->left) {
            localMinimal = localMinimal->left;
        }
        tempNode->key = minimalCurrent->key;
        int tempKey = localMinimal->key;
        this->remove(localMinimal->key);
        minimalCurrent->key = tempKey;
        return  true;

    } else {
        int tempKey = minimalCurrent->key;
        this->remove(minimalCurrent->key);
        tempNode->key = tempKey;
        return true;
    }
}

int BinarySearchTree::getCount()
{
    return this->count;
}

bool BinarySearchTree::remove(int value)
{
    bool finded = false;

    Node* tempNode = this->root;

    while(!finded) {
        if(tempNode == nullptr) {
            return false;
        }
        if( value >= tempNode->key ) {
            Node* current = nullptr;
            if(value == tempNode->key) {
                current = tempNode;
            } else {
                current = tempNode->right;
            }
            if(current->key == value) {
                if(!current->left && !current->right) {
                    delete current;
                    tempNode->right = nullptr;
                    return true;
                }
                if(current->right && !current->left) {
                    tempNode->right = current->right;
                    delete  current;
                    return true;
                }
                if(current->left && current->right) {
                    this->removeTwo(current, tempNode);
                    return true;
                }
            } else {
                tempNode = tempNode->right;
            }

        } else {
                 Node* current = tempNode->left;
               if(current->key == value) {
                   if(!current->left && !current->right) {
                       delete current;
                       tempNode->left = nullptr;
                       return true;
                   }
                   if(current->left && !current->right) {
                       tempNode->left = current->left;
                       delete current;
                       return true;
                   }
                   if(current->left && current->right) {
                       this->removeTwo(current, tempNode);
                       return true;
                   }

               } else {
                 tempNode = tempNode->left;
               }
        }
    }
    return false;
}

void BinarySearchTree::walk()
{
    this->_walk(this->root);
}

int BinarySearchTree::min() const// в чём фишка константынх функций
{
    Node* tempNode = this->root;
    while(tempNode->left) {
        tempNode = tempNode->left;
    }
    return tempNode->key;
//    nestedMin(this->root);
}
//int BinarySearchTree::nestedMin(Node *minimal) const
//{
//    Node* tempNode = minimal;
//    while(tempNode->left) {
//        tempNode = tempNode->left;
//    }
//    return tempNode->key;
//}

int BinarySearchTree::max() const
{
    Node* tempNode = this->root;

    while(tempNode->right) {
        tempNode = tempNode->right;
    }
    return tempNode->key;
}

void BinarySearchTree::clear()
{
    this->_clear(this->root);
    this->root = nullptr;
}

void BinarySearchTree::_walk(Node *root)
{
    if(!root) return;
    _walk(root->left);
    qDebug()<<root->key;

    _walk(root->right);
}

void BinarySearchTree::_clear(Node *root)
{
    if(root != nullptr) {
        _clear(root->left);
        _clear(root->right);
        delete root;
        root = nullptr;
    }
}

//Node *BinarySearchTree::findMinNode(int value, Node *current)
//{
//    while(current->left) {
//        current = current->left;
//    }
//    return current;
//}




