#include <iostream>

class BNode {
public:
    int* keys;
    int t;
    BNode **C;
    int n;
    bool isLeaf;

    BNode(int _t, bool _isLeaf);

    void traverse();

    void insertNonFull(int k);

    void splitChild(BNode *y, int i);

    BNode *search(int k);

    friend class BTree;
};