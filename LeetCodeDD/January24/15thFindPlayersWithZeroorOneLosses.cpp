//
// Created by karan on 1/15/2024.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        int present[100001] = {0};
        int loss[100001] = {0};
        int n = matches.size();
        for (int i = 0; i < n; i++) {
            present[matches[i][0]] = 1;
            present[matches[i][1]] = 1;
            loss[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for (int i = 1; i < 100001; i++) {
            if (!present[i]) continue;
            if (loss[i] == 0) ans[0].push_back(i);
            else if (loss[i] == 1) ans[1].push_back(i);
        }
        return ans;
    }
};