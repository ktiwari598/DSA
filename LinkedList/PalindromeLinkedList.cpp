//
// Created by karan on 1/29/2024.
//
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode *reverse(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }

    bool isPalindrome(ListNode *root) {
        ListNode *temp = root;
        int n = 0;
        ListNode *hare = root, *tort = root;
        while (hare && hare->next && tort) {
            hare = hare->next->next;
            tort = tort->next;
        }
        if (hare && !hare->next) {
            tort = tort->next;
        }
        ListNode *tail = reverse(tort);
        while (root && tail) {
            if (root->val != tail->val) return false;
            root = root->next;
            tail = tail->next;
        }
        return true;
    }
};

