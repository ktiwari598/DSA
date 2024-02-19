//
// Created by karan on 2/19/2024.
//
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

//PRINT LEFT BOUNDARY NODE WITHOUT LEAVES
void printLeftBoundaryNode(Node *root, vector<int> &res) {
    if (!root) return;

    if (root->left) {
        res.push_back(root->data);
        printLeftBoundaryNode(root->left, res);
    } else if (root->right) {
        res.push_back(root->data);
        printLeftBoundaryNode(root->right, res);
    }
}

//PRINT RIGHT BOUNDARY NODE WITHOUT LEAVES
void printRightBoundaryNode(Node *root, vector<int> &res) {
    if (!root) return;

    if (root->right) {
        printRightBoundaryNode(root->right, res);
        res.push_back(root->data);
    } else if (root->left) {
        printRightBoundaryNode(root->left, res);
        res.push_back(root->data);
    }
}

//PRINT LEAVES NODE
void printLeaves(Node *root, vector<int> &res) {
    if (!root) return;

    printLeaves(root->left, res);

    if (!root->left && !root->right) {
        res.push_back(root->data);
        return;
    }

    printLeaves(root->right, res);
}

vector<int> boundary(Node *root) {
    vector<int> res;
    if (!root) return res;
    res.push_back(root->data);

    printLeftBoundaryNode(root->left, res);
    printLeaves(root->left, res);
    printLeaves(root->right, res);
    printRightBoundaryNode(root->right, res);

}