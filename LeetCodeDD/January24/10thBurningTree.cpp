//
// Created by karan on 1/10/2024.
//
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    /**
     * Approach 2
     * Single DFS
     * TC O(N), SC O(N)
     */

    bool pathToStart(TreeNode *root, int start, vector<TreeNode *> &path) {
        if (!root) return false;
        if (root->val == start) {
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if (pathToStart(root->left, start, path) || pathToStart(root->right, start, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    int height(TreeNode *root, TreeNode *blockNode) {
        if (!root || root == blockNode) return 0;
        return 1 + max(height(root->left, blockNode), height(root->right, blockNode));
    }

    int amountOfTime(TreeNode *root, int start) {
        vector<TreeNode *> path;
        pathToStart(root, start, path);
        path.push_back(NULL);
        int n = path.size() - 1, ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = max(ans, n - 1 - i + height(path[i], path[i + 1]));
        }
        return ans - 1;
    }

    //Approach 1
    //2 times traversal, convert tree to graph, then do BFS
    /*
     int dfs(TreeNode* root, int parent, unordered_map<int, unordered_set<int>>& mp) {
        if(!root) return -1;

        if(parent != -1) {
            mp[root->val-1].insert(parent-1);
        }

        int left = dfs(root->left, root->val, mp);
        int right = dfs(root->right, root->val, mp);

        if(left != -1) mp[root->val-1].insert(left-1);
        if(right != -1) mp[root->val-1].insert(right-1);
        return root->val;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, unordered_set<int>> mp;
        dfs(root, -1, mp);

        int ans = 0;
        int msize = mp.size();
        if(msize == 0) return 0;
        unordered_set<int> visited;
        queue<int> q;
        q.push(start-1);
        visited.insert(start-1);
        while(!q.empty()) {
            int x = q.size();
            for(int i=0;i<x;i++) {
                int temp = q.front();
                q.pop();
                for(auto child: mp[temp]) {
                    if(visited.find(child) == visited.end()) {
                        q.push(child);
                        visited.insert(child);
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
     */

};