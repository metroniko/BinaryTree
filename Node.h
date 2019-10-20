#ifndef NODE_H
#define NODE_H



struct Node {
    Node(int key) {
        this->key = key;
}
    int size = 1;
    int key;
    Node* left{nullptr};
    Node* right{nullptr};


};


#endif // NODE_H
