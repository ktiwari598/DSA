//
// Created by karan on 1/26/2024.
//

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:

    // int dp[1001][1001];

    // int solve(int i, int j, string& text1, string& text2) {
    //     if(i == text1.length() || j == text2.length()) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int ans;
    //     if(text1[i] == text2[j]) {
    //         ans = 1 + solve(i+1, j+1, text1, text2);
    //     }
    //     else {
    //         ans = max(solve(i, j+1, text1, text2), solve(i+1, j, text1, text2));
    //     }
    //     return dp[i][j] = ans;
    // }

    int longestCommonSubsequence(string text1, string text2) {
        // memset(dp, -1, sizeof(dp));
        // return solve(0, 0, text1, text2);
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};