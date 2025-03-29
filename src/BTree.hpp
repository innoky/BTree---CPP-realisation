#include "BNode.hpp"


class BTree
{
public:
    BNode* root;
    int t;

    BTree(int _t)
    {
        root = nullptr;
        t = _t;
    }

    void traverse()
    {
        if (root != nullptr)
            root->traverse();
    }

    BNode *search(int k) { return (root == nullptr) ? nullptr : root->search(k); }

    void insert(int k);

};