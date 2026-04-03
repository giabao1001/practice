#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    int height;
    Node (int key){
        data = key;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int getHeight (Node * N){
    if ( N == nullptr ) return 0;
    return N->height;
}

int getBalance (Node * N){
    if ( N == nullptr ) return 0;
    return getHeight(N->left) - getHeight(N->right);
}

Node * rightRotate(Node * n1){
    Node * n1Left = n1->left;
    Node * n2Right = n1Left->right;
    // rotate
    n1Left->right = n1;
    n1->left = n2Right;

    n1->height = max( getHeight(n1->left), getHeight(n1->right)) + 1;
    n1Left->height = max(getHeight(n1Left->right),getHeight(n1Left->left))+1;

    return n1Left;
}

Node * leftRotate (Node* n1){
    Node *n1Right = n1->right;
    Node *n2Left = n1Right->left;

    n1Right->left = n1;
    n1->right = n2Left;

    n1->height = max( getHeight(n1->left), getHeight(n1->right)) + 1;
    n1Right->height = max(getHeight(n1Right->right),getHeight(n1Right->left))+1;

    return n1Right;
}

Node *insert (Node * node, int key){
    // find destination -> create node
    if (node == nullptr) return new Node (key);

    // navigate
    if ( key < node->data ) node -> left = insert(node->left,key);
    else if ( key > node->data ) node ->right = insert(node->right,key);
    else return node;

    // calculation
    node -> height = max ( getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // check balance

    // left left
    if ( balance > 1 && key < node -> data ){
        return rightRotate(node);
    }

    //right right
     if ( balance < -1 && key > node -> data ){
        return leftRotate(node);
    }

    // left right 
    if ( balance > 1 && key > node -> data ){
        node -> left = leftRotate(node->left);
        return rightRotate(node);
    }

    // right left 
    if ( balance < -1  && key < node -> data ){
    node -> right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main() {
    Node * root = nullptr;
    for (int i = 0; i < 10; ++ i){
        insert(root,i);
    }
    return 0;
}