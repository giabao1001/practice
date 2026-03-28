#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    int height;

    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}
// Right Rotate (used for Left-Heavy situations)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // New root
}

// Left Rotate (used for Right-Heavy situations)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // New root
}

Node* insert(Node* node, int val) {
    // 1. Standard BST Insertion
    if (!node) return new Node(val);

    if (val < node->data)
        node->left = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);
    else
        return node; // Duplicates not allowed

    // 2. Update height of this ancestor node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Get balance factor to check for unbalance
    int balance = getBalance(node);

    // Case 1: Left Left (LL)
    if (balance > 1 && val < node->left->data)
        return rightRotate(node);

    // Case 2: Right Right (RR)
    if (balance < -1 && val > node->right->data)
        return leftRotate(node);

    // Case 3: Left Right (LR)
    if (balance > 1 && val > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Case 4: Right Left (RL)
    if (balance < -1 && val < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main() {
    
    return 0;
}