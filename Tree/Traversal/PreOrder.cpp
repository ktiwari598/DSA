//
// Created by karan on 2/19/2024.
//
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> preorderTraversal(TreeNode *root) {
    TreeNode *cur = root;
    stack<TreeNode *> st;
    vector<int> vect;
    while (cur != NULL || !st.empty()) {
        while (cur != NULL) {
            st.push(cur);
            vect.push_back(cur->val);
            cur = cur->left;
        }
        cur = st.top();
        st.pop();
        cur = cur->right;
    }
    return vect;
}

void preOrder(TreeNode *root) {
    if (!root) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}