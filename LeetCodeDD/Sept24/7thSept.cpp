//
// Created by karan on 9/8/2024.
//
/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

/**
 * Definition for a binary tree node.
 */
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

    bool solve(ListNode* head, TreeNode* root) {
        //Base Case
        if(!head) return true;
        if(!root) return false;

        //Find the starting node that matches the head
        bool left = false, right = false;
        if(root->val == head->val) {
            left = solve(head->next, root->left);
            right = solve(head->next, root->right);
        }
        return left || right;
    }

    void preorder(TreeNode* root, vector<TreeNode*>& path, int val) {
        if(!root) return;
        if(root->val == val) path.push_back(root);
        preorder(root->left, path, val);
        preorder(root->right, path, val);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<TreeNode*> path;
        bool ans = false;
        preorder(root, path, head->val);
        for(int i=0;i<path.size();i++) {
            ans = ans || solve(head, path[i]);
        }
        return ans;
    }
};