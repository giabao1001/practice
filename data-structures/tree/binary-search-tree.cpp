#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node () {
        left = nullptr;
        right = nullptr;
    }
};

void insert (Node * &root, int val) {
    if ( !root ){
        Node * newNode = new Node;
        newNode->data = val;
        root = newNode;
        return;
    }
    else {
    if ( val < (root->data) ){
        insert(root->left,val);
    }

     else if ( val > (root->data) ){
        insert(root->right,val);
        }
    }
}

Node * findSmallest(Node* root){
    Node * temp = root;
    while ( temp -> left != nullptr){
        temp = temp->left;
    }
    return temp;
}

void deleteNode (Node *& root, int val){
    if ( root->data == val){
        // case 1: 
        if ( root->left == nullptr && root->right == nullptr ){
            delete root;
            root = nullptr;
        }
        //case 2:
        else if ( root->left != nullptr && root->right != nullptr){
            Node * replacement = findSmallest (root->right);
            root->data = replacement->data;
            delete replacement;
            replacement = nullptr;
        }
        //case 3: 
        else {
            if (root->left == nullptr){
                root->data = root->right->data;
                delete root;
                root = nullptr;
            }
            if (root->right == nullptr){
                root->data = root->left->data;
                delete root;
                root = nullptr;
            }
        }
    }
    else {
        if (root != nullptr){
        if ( val > root->data ){
            deleteNode(root->right,val);
        }
        else {
            deleteNode(root->left,val);
        }
    }
        else {
        return;
    }
    }
}

int main() {
    int n;
    cin >> n; 
    Node * root = nullptr;
    for ( int i = 0; i < n; ++i){
        int temp; 
        cin >> temp;
        insert(root,temp);
    }
    return 0;
}