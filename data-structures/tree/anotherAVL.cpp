#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node * right;
    int height;
    Node (int data){
        key = data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int getHeight(Node* curr){
    if (curr == nullptr) return 0;
    return curr->height;
}

int getBalance(Node *curr){
    if (curr == nullptr) return 0;
    return getHeight(curr->left) - getHeight(curr->right);
}

Node * rightRotate (Node * curr){
    
}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    return 0;
}