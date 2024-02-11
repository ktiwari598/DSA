//
// Created by karan on 2/11/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int dif = 0; dif < n; dif++) {
            for (int i = 0, j = dif; j < n; j++, i++) {
                if (j - i == 0) dp[i][j] = 1;
                else if (j - i == 1) dp[i][j] = (s[j] == s[i]);
                else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if (dp[i][j] > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};