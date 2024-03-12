//
// Created by karan on 3/12/2024.
//

#include<bits/stdc++.h>

using namespace std;

ListNode *removeZeroSumSublists(ListNode *head) {
    unordered_map<int, ListNode *> mp;
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *temp = head;
    mp[0] = dummyNode;
    int sum = 0;
    while (temp) {
        sum += temp->val;
        if (mp.count(sum) > 0) {
            ListNode *tempo = mp[sum];
            ListNode *cur = tempo->next;
            int p = sum + cur->val;
            while (p != sum) {
                mp.erase(p);
                cur = cur->next;
                p += cur->val;
            }
            tempo->next = temp->next;
        } else {
            mp[sum] = temp;
        }
        temp = temp->next;
    }
    return dummyNode->next;
}