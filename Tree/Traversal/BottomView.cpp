//
// Created by karan on 2/19/2024.
//

#include<bits/stdc++.h>

using namespace std;

vector<int> bottomView(Node *root) {
    queue<pair<Node *, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            auto temp = q.front();
            q.pop();

            mp[temp.second] = temp.first->data;

            if (temp.first->left) {
                q.push({temp.first->left, temp.second - 1});
            }

            if (temp.first->right) {
                q.push({temp.first->right, temp.second + 1});
            }
        }
    }
    vector<int> ans;
    for (auto it: mp) {
        ans.push_back(it.second);
    }
    return ans;
}