#include "BTree.hpp"

void BTree::insert(int k)
{
    if (!root) {
        root = new BNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    }
    else {
        if (root->n == 2 * t - 1)
        {
            BNode *s = new BNode (t, false);
            s->C[0] = root;
            s->splitChild(root, 0);
            int i = (s->keys[0] < k)? 1 : 0;
            s->C[i]->insertNonFull(k);
            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

