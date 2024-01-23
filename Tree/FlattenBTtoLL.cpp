//
// Created by karan on 1/23/2024.
//
#include<bits/stdc++.h>

using namespace std;


void flatten(TreeNode *root) {
    if (!root || (!root->left && !root->right)) return;
    if (root->left) {
        flatten(root->left);
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        TreeNode *it = root;
        while (it->right) {
            it = it->right;
        }
        it->right = temp;
    }
    flatten(root->right);
}