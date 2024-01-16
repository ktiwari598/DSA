//
// Created by karan on 1/16/2024.
//
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
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    ListNode *reverse(ListNode *head, ListNode *end) {
        if (head == end || head->next == end) {
            return head;
        }
        ListNode *temp = reverse(head->next, end);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) return head;
        ListNode *temp = head;
        int i = 0;
        while (i < k && temp) {
            temp = temp->next;
            i++;
        }
        if (i < k) return head;
        ListNode *reverseEnd = reverse(head, temp);
        head->next = reverseKGroup(temp, k);
        return reverseEnd;
    }
};