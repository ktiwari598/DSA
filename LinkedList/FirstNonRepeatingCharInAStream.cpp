//
// Created by karan on 1/18/2024.
//

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int a) {
        this->data = a;
        this->left = NULL;
        this->right = NULL;
    }
};

string FirstNonRepeating(string A) {
    Node *head = NULL, *tail = NULL;
    string ans = "";
    vector<Node *> vect(26, NULL);
    int freq[26] = {0};
    int n = A.length();
    for (int i = 0; i < n; i++) {
        int ch = A[i] - 'a';
        if (freq[ch] == 0) {
            Node *temp = new Node(ch);
            if (!head) {
                head = temp;
                tail = temp;
            } else {
                tail->right = temp;
                temp->left = tail;
                tail = temp;
            }
            vect[ch] = tail;
        } else {
            Node *temp = vect[ch];
            if (!head) {
                ans += "#";
                continue;
            }
            if (!temp) {
                ans += (head->data + 'a');
                continue;
            }
            if (temp == head) {
                Node *nextNode = temp->right;
                if (nextNode) {
                    nextNode->left = NULL;
                }
                head->right = NULL;
                head = nextNode;
            } else if (temp == tail) {
                Node *prevNode = temp->left;
                prevNode->right = NULL;
                tail->left = NULL;
                tail = prevNode;
            } else {
                Node *prevNode = temp->left;
                Node *nextNode = temp->right;
                prevNode->right = nextNode;
                nextNode->left = prevNode;
                temp->right = NULL;
                temp->left = NULL;
            }
            vect[ch] = NULL;
        }
        if (head) ans += (head->data + 'a');
        else ans += "#";
        freq[ch] += 1;
    }
    return ans;
}

int main() {
    cout << FirstNonRepeating("abcdcabd") << endl;
    cout << FirstNonRepeating("aaa") << endl;
    cout << FirstNonRepeating("a") << endl;
    cout << FirstNonRepeating("tcpmxaixsswjelbswxytyhbwjinuhxhvpwaybmdhndafszoghpyzdahiqsgluufqcekjk") << endl;
}
