#ifndef BTREE_H
#define BTREE_H

#include "Product.h"
#include <iostream>
#define T 3  // Minimum degree (defines the range for number of keys)

class BTreeNode {
public:
    Product* keys[2*T - 1];
    BTreeNode* children[2*T];
    int n;
    bool leaf;

    BTreeNode(bool isLeaf);
    void traverse();
    Product* search(int id);
    void insertNonFull(Product* k);
    void splitChild(int i, BTreeNode* y);

    friend class BTree;
};

class BTree {
private:
    BTreeNode* root;
public:
    BTree();
    void traverse();
    Product* search(int id);
    void insert(Product* k);
};

#endif // BTREE_H