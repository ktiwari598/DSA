//
// Created by karan on 2/7/2024.
//

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it: mp) {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            while (temp.first--) ans += temp.second;
        }
        return ans;
    }
};