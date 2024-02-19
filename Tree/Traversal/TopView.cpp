//
// Created by karan on 2/19/2024.
//

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

//Use Level Order Traversal and just insert the element in map
vector<int> topView(Node *root) {
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node *temp = q.front().first;
            int ind = q.front().second;
            q.pop();

            if (mp.count(ind) == 0) {
                mp[ind] = temp->data;
            }

            if (temp->left) {
                q.push({temp->left, ind - 1});
            }

            if (temp->right) {
                q.push({temp->right, ind + 1});
            }
        }
    }
    vector<int> ans;
    for (auto it: mp) {
        ans.push_back(it.second);
    }
    return ans;
}