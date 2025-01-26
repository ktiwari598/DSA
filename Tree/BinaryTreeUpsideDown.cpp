//
// Created by Karan Tiwari on 25/01/25.
//
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    explicit Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* upsideDown(Node* root) {
   if(!root || !root->left) return root;
   Node* newRoot = upsideDown(root->left);
   root->left->left = root->right;
   root->left->right = root;
   root->left = NULL;
   root->right = NULL;
   return newRoot;
}

void preorder(Node* root) {
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Node* newRoot = upsideDown(root);
    preorder(newRoot);

}