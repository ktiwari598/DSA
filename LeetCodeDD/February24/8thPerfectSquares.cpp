//
// Created by karan on 2/8/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int dp[10001];

    int solve(int n) {
        //Base Case
        if (n <= 0) return 0;

        if (dp[n] != -1) return dp[n];
        //Recursive Intuition
        int x = floor(sqrt(n));
        int ans = INT_MAX;
        for (int i = 1; i <= x; i++) {
            ans = min(ans, 1 + solve(n - i * i));
        }
        return dp[n] = ans;
    }

    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};