//
// Created by karan on 1/18/2024.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string FirstNonRepeating(string A) {
        queue<char> q;
        string ans = "";
        int freq[26] = {0};
        int n = A.length();
        for (int i = 0; i < n; i++) {
            freq[A[i] - 'a'] += 1;
            if (freq[A[i] - 'a'] == 1) {
                q.push(A[i]);
                ans = ans + q.front();
            } else {
                if (A[i] == q.front()) {
                    while (!q.empty()) {
                        char ch = q.front();
                        if (freq[ch - 'a'] == 1) {
                            ans = ans + ch;
                            break;
                        }
                        q.pop();
                    }
                    if (q.empty()) ans += "#";
                } else {
                    if (q.empty()) ans += "#";
                    else {
                        ans = ans + q.front();
                    }
                }
            }
        }
        return ans;
    }
};


//abcdcabd
//ABCD

//aaaaabd#