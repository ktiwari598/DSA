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

//Iterative Post Order Traversal
vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> vect;
    TreeNode *cur = root;
    while (cur != NULL || !st.empty()) {
        while (cur != NULL) {
            vect.push_back(cur->val);
            st.push(cur);
            cur = cur->right;
        }
        cur = st.top();
        st.pop();
        cur = cur->left;
    }
    reverse(vect.begin(), vect.end());
    return vect;
}

void solve(TreeNode *root, vector<int> &ans) {
    if (!root) return;
    solve(root->left, ans);
    solve(root->right, ans);
    ans.push_back(root->val);
}

//Recursive Post Order Traversal
vector<int> postOrder(TreeNode *root) {
    vector<int> res;
    solve(root, res);
    return res;
}