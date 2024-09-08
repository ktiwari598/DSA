//
// Created by karan on 9/8/2024.
//

/**
 * <a href="https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08">
 * https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08
 * </a/
 */

struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

int getListSize(ListNode* head) {
    int count = 0;
    while(head) {
        head = head->next;
        count++;
    }
    return count;
}

vector<ListNode*> splitListToParts(ListNode* head, int k) {
    ListNode* temp = head;
    int listSize = getListSize(temp);
    vector<ListNode*> ans;
    while(listSize > 0 || k > 0) {
        int curSize = ceil((1.0 * listSize)/k);
        ans.push_back(temp);
        for(int i=0;i<curSize;i++) {
            ListNode* next = temp->next;
            if(i == curSize-1) temp->next = NULL;
            temp = next;
        }
        listSize = listSize - curSize;
        k--;
    }
    return ans;
}