#include "BTree.h"
#include <iostream>

// BTreeNode constructor
BTreeNode::BTreeNode(bool isLeaf) {
    leaf = isLeaf;
    n = 0;
    for (int i = 0; i < 2*T; i++)
        children[i] = nullptr;
    for (int i = 0; i < 2*T - 1; i++)
        keys[i] = nullptr;
}

// Traverse the tree in-order
void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf)
            children[i]->traverse();
        if (keys[i]) keys[i]->display();
    }
    if (!leaf)
        children[i]->traverse();
}

// Search for a product by ID
Product* BTreeNode::search(int id) {
    int i = 0;
    while (i < n && id > keys[i]->id)
        i++;
    if (i < n && keys[i]->id == id)
        return keys[i];
    if (leaf)
        return nullptr;
    return children[i]->search(id);
}

// Insert a new product in a non-full node
void BTreeNode::insertNonFull(Product* k) {
    int i = n - 1;
    if (leaf) {
        while (i >= 0 && k->id < keys[i]->id) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n++;
    } else {
        while (i >= 0 && k->id < keys[i]->id)
            i--;
        i++;
        if (children[i]->n == 2*T - 1) {
            splitChild(i, children[i]);
            if (k->id > keys[i]->id)
                i++;
        }
        children[i]->insertNonFull(k);
    }
}

// Split the child of a node
void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j + T];

    if (!y->leaf) {
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j + T];
    }

    y->n = T - 1;

    for (int j = n; j >= i + 1; j--)
        children[j + 1] = children[j];
    children[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];
    keys[i] = y->keys[T - 1];

    n++;
}

// BTree constructor
BTree::BTree() {
    root = nullptr;
}

// Traverse the B-Tree
void BTree::traverse() {
    if (root) root->traverse();
    else std::cout << "[Empty Tree]\n";
}

// Search wrapper
Product* BTree::search(int id) {
    return (root == nullptr) ? nullptr : root->search(id);
}

// Insert wrapper
void BTree::insert(Product* k) {
    if (!root) {
        root = new BTreeNode(true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == 2*T - 1) {
            BTreeNode* s = new BTreeNode(false);
            s->children[0] = root;
            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0]->id < k->id)
                i++;
            s->children[i]->insertNonFull(k);

            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}