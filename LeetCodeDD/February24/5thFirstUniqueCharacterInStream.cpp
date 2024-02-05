//
// Created by karan on 2/5/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        int freq[26] = {0};
        for(int i=0;i<s.length();i++) {
            freq[s[i] - 'a']++;
            if(freq[s[i]-'a'] == 1) {
                q.push(i);
            } else {
                if(!q.empty() && s[i] == s[q.front()]) {
                    while(!q.empty()) {
                        if(freq[s[q.front()] - 'a'] == 1) {
                            break;
                        }
                        q.pop();
                    }
                }
            }
        }
        if(q.empty()) return -1;
        return q.front();
    }
};