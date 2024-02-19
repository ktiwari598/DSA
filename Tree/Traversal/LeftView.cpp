//
// Created by karan on 2/19/2024.
//
#include<bits/stdc++.h>

using namespace std;

vector<int> leftView(Node *root) {
    vector<int> res;
    if (!root) return res;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {

            Node *temp = q.front();
            q.pop();

            if (i == 0) {
                res.push_back(temp->data);
            }

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }

    return res;
}