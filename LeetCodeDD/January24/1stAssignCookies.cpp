//
// Created by karan on 1/13/2024.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, n = g.size(), used = 0;
        int i = 0, j = 0;
        while (i < n && j < s.size()) {
            if (s[j] >= g[i]) i++;
            j++;
        }
        return i;
    }
};