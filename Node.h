#ifndef NODE_H
#define NODE_H

#endif // NODE_H
struct Node {
    Node(int key) {
        this->key = key;
}
    int key;
    Node* left{nullptr};
    Node* right{nullptr};

};
