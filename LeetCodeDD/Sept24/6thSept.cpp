//
// Created by karan on 9/8/2024.
//
/**
 * <a href="https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-06">
 * https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2024-09-06
 * </a>
 */

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
    ListNode *modifiedList(vector<int> &nums, ListNode *head) {
        unordered_set<int> st;
        for (int i: nums) {
            st.insert(i);
        }
        ListNode *dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode *prev = dummyNode, *temp = head;
        while (temp) {
            if (st.find(temp->val) != st.end()) {
                //cout<<temp->val<<endl;
                ListNode *temp2 = temp->next;
                temp->next = NULL;
                if (temp == head) {
                    head = temp2;
                }
                prev->next = temp2;
                temp = temp2;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};