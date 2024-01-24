//
// Created by karan on 1/24/2024.
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

class Solution {
public:

    /*
     * TC - O(logK)
     * SC - O(1)
     * Pehle left tak jao, kyoki left pe smallest element h, but left jate waqt right jake righmost
     * ko parent ke sath attach kardo, fir left se traverse karte aao, elements sorted milenge
     */
    int kthSmallest(TreeNode *root, int k) {
        if (!root) return 0;
        while (k > 0) {
            TreeNode *start = root, *prev = root->left;
            if (!prev) {
                k--;
                if (k == 0) break;
                root = root->right;
                continue;
            }
            while (prev->right) {
                prev = prev->right;
            }
            prev->right = start;
            TreeNode *temp = root->left;
            root->left = NULL;
            root = temp;
        }
        return root->val;
    }


    /*
     * TC - O(logN)
     * SC - O(1)
     */
    void inorder(TreeNode *root, int &k, int &ans) {
        if (!root) return;

        inorder(root->left, k, ans);
        if (ans != -1) return;
        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans);
    }

    int kthSmallest1(TreeNode *root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};