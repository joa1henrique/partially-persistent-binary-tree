#ifndef BST_HPP
#define BST_HPP

#include <limits>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val);
Node* removeNode(Node* root, int val, bool& found);
Node* findMin(Node* root);
int successor(Node* root, int val);
void printTree(Node* root, int depth, bool& first);

extern Node* versions[100];
extern int current_version;
extern const int INFINITO;

#endif
