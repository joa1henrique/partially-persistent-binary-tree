#include "bst.hpp"
#include <iostream>

using namespace std;

Node* versions[100];
int current_version = 0;
const int INFINITO = numeric_limits<int>::max();

Node* insert(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }
    Node* n = new Node(root->val);
    n->left = root->left;
    n->right = root->right;
    if (val < n->val) {
        n->left = insert(n->left, val);
    } else {
        n->right = insert(n->right, val);
    }
    return n;
}

Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

Node* removeNode(Node* root, int val, bool& found) {
    if (!root) return nullptr;
    if (val < root->val) {
        Node* left_child = removeNode(root->left, val, found);
        if (!found) return root;
        Node* n = new Node(root->val);
        n->left = left_child;
        n->right = root->right;
        return n;
    } else if (val > root->val) {
        Node* right_child = removeNode(root->right, val, found);
        if (!found) return root;
        Node* n = new Node(root->val);
        n->left = root->left;
        n->right = right_child;
        return n;
    } else {
        found = true;
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        Node* temp = findMin(root->right);
        Node* n = new Node(temp->val);
        n->left = root->left;
        bool dummy = false;
        n->right = removeNode(root->right, temp->val, dummy);
        return n;
    }
}

int successor(Node* root, int val) {
    int succ = INFINITO;
    Node* curr = root;
    while (curr) {
        if (curr->val > val) {
            succ = curr->val;
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    return succ;
}

void printTree(Node* root, int depth, bool& first) {
    if (!root) return;
    printTree(root->left, depth + 1, first);
    if (!first) {
        cout << " ";
    }
    cout << root->val << "," << depth;
    first = false;
    printTree(root->right, depth + 1, first);
}
