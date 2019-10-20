#include "randombst.h"
#include "Node.h"
#include "random"
#include <QDebug>

RandomBST::RandomBST()
{

}

void RandomBST::insert(int key)
{
   this->root = this->insertIn( this->root, key);
}

void RandomBST::remove(int value)
{
    this->_remove(this->root, value);
}
Node *RandomBST::_remove(Node *root, int value)
{
    if (!root) return root;
    if(root->key == value) {
        Node* tempNode = _join(root->left, root->right);
        delete root;
        return tempNode;
    } else if(value < root->key) {
        root->left = _remove(root->left, value);
    } else {
        root->right = _remove(root->right, value);
    }
    return root;

}

Node *RandomBST::_join(Node* left, Node* right)
{
        if( !left ) return right;
        if( !right ) return left;
        if( rand()%(left->size+right->size) < left->size )
        {
            left->right = _join(left->right,right);
            fixsize(left);
            return left;
        }
        else
        {
            right->left = _join(left,right->left);
            fixsize(right);
            return right;
        }
}


bool RandomBST::find(int value)
{
    return (findNode(this->root, value)? true: false);
}

void RandomBST::walk()
{
    this->_walk(this->root);
}

void RandomBST::clear()
{
    this->_clear(this->root);
    this->root = nullptr;
}

int RandomBST::min() const
{

    Node* tempNode = this->root;
    while(tempNode->left) {
        tempNode = tempNode->left;
    }
    return tempNode->key;

}

int RandomBST::max() const
{
    Node* tempNode = this->root;

    while(tempNode->right) {
        tempNode = tempNode->right;
    }
    return tempNode->key;
}

void RandomBST::_clear(Node *root)
{
    if(root != nullptr) {
        _clear(root->left);
        _clear(root->right);
        delete root;
        root = nullptr;
    }
}
void RandomBST::_walk(Node *root)
{
    if(!root) return;
    _walk(root->left);
    qDebug()<<root->key;

    _walk(root->right);
}


Node *RandomBST::findNode(Node *current, int value)
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
Node *RandomBST::insertIn(Node *node, int key)
{
    if(!node) {// если нет корня
        return new Node(key);
    }
    if((rand() % node->size + 1) == 0) {// вместо rand 12
        return insertAsRoot(node, key);
    }
    if(key< node->key) {
        node->left = insertIn(node->left, key);
    } else {
        node->right = insertIn(node->right, key);
    }
    fixsize(node);
    return node;
}

Node *RandomBST::insertAsRoot(Node *node, int key)
{
    if(!node) return new Node(node->key);
    if( key < node->key ) {
        if( key < node->key ) {
            node->left = insertAsRoot(node->left, key);
            return rotateRight(node);
        } else {
            node->right = insertAsRoot(node->right, key);
            return rotateLeft(node);
        }
    }
}

Node *RandomBST::rotateLeft(Node *node)
{
    Node* tempNode = node->right;//8
    if(!tempNode) return node;
    node->right = tempNode->left;//null
    tempNode->left = node;//8
    tempNode->size = node->size;
    fixsize(node);
    return tempNode;
}

Node *RandomBST::rotateRight(Node *node)
{
    Node* tempNode = node->left;
    if(tempNode) return node;
    node->left = tempNode->right;
    tempNode->right = node;
    tempNode->size = node->size;
    fixsize(node);
    return tempNode;
}

void RandomBST::fixsize(Node *node)
{
    node->size = getSize(node->left)+getSize(node->right)+1;
}

int RandomBST::getSize(Node *node)
{
    if (!node) {
        return 0;
    }
    return node->size;
}



