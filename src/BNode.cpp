#include "BNode.hpp"

BNode::BNode(int _t, bool _isLeaf)
{
    t = _t;
    isLeaf = _isLeaf;
    keys = new int[2 * t - 1];
    C = new BNode *[2 * t];
    n = 0;
}

void BNode::traverse()
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!isLeaf)
            C[i]->traverse();
        std::cout << " " << keys[i];
    }
    if (!isLeaf)
        C[i]->traverse();
}

BNode *BNode::search(int k)
{
    int i = 0;

    while (i < n && k > keys[i])
        i++;

    if (keys[i] == k)
        return this;
    if (isLeaf)
        return nullptr;

    return C[i]->search(k);
}

void BNode::splitChild(BNode *y, int i)
{
    BNode *z = new BNode(y->t, y->isLeaf);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];

    if (!y->isLeaf) {
        for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
    }

    y->n = t - 1;

    for(int j = n; j >= i + 1; j--) C[j + 1] = C[j];
    C[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];
    n++;
}

void BNode::insertNonFull(int k)
{
    int i = n - 1;
    if (isLeaf)
    {
        while (i >= 0 && keys[i] > k)
        {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n++;
    }
    else
    {
        while (i >= 0 && keys[i] > k)
            i--;
        i++;
        if (C[i]->n == 2 * t - 1)
        {
            splitChild(C[i], i);
            if (keys[i] < k)
                i++;
        }
        C[i]->insertNonFull(k);
    }
}