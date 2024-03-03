//
// Created by karan on 3/3/2024.
//

#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(NULL) {}

    ListNode(int x) : val(x), next(NULL) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Recursive Approach
void solve(ListNode *head, int &k) {
    if (!head) return;

    solve(head->next, k);
    if (k == 0) {
        ListNode *temp = head->next;
        head->next = head->next->next;
        temp->next = NULL;
    }
    k--;
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    //if(!head->next and n == 1) return NULL;
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    solve(dummy, n);
    return dummy->next;
}

//Iterative Approach, keep gap of n between hare and tortoise node
ListNode *removeNthFromEndIterative(ListNode *head, int n) {
    ListNode *hare = head, *tail = head;
    while (n > 0 && hare) {
        hare = hare->next;
        n--;
    }

    if (!hare) return head->next;

    while (hare->next) {
        hare = hare->next;
        tail = tail->next;
    }

    ListNode *temp = tail->next;
    tail->next = tail->next->next;
    temp->next = NULL;
    return head;
}