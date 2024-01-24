//
// Created by karan on 1/24/2024.
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

    bool canBePalindrome(unordered_map<int, int> &mp) {
        int count = 0;
        //If freq of all elements is even or only element is odd, then canBePlaindrome is true
        for (auto itr: mp) {
            if (itr.second & 1) count++;
            if (count > 1) return false;
        }
        return true;
    }

    void solve(TreeNode *root, unordered_map<int, int> &freq, int &count) {
        //Base Case
        if (!root) return;

        freq[root->val]++;

        if (!root->left && !root->right) {
            if (canBePalindrome(freq)) {
                count++;
            }
            freq[root->val]--;
            return;
        }

        //Recursive Intuition
        solve(root->left, freq, count);
        solve(root->right, freq, count);
        freq[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root) {
        unordered_map<int, int> mp;
        int count = 0;
        solve(root, mp, count);
        return count;
    }
};

/*
1. Iterate through the tree in preorder and increment the fre arr for each node
2. while coming back I will decrement the freq arr
3. If node is leaf node then I will check if it can be pseudo-palindrome path
*/