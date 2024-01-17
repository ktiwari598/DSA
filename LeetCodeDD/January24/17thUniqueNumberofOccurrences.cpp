//
// Created by karan on 1/17/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        for (auto it: mp) {
            if (st.count(it.second) > 0) {
                return false;
            }
            st.insert(it.second);
        }
        return true;
    }
};

