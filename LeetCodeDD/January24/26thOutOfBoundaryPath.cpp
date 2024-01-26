//
// Created by karan on 1/26/2024.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int dp[51][51][51];

    int mod = 1e9 + 7;

    bool isSafe(int m, int n, int row, int col) {
        return row >= 0 && row < m && col >= 0 && col < n;
    }


    int solve(int m, int n, int maxMove, int startRow, int startColumn) {
        //Base Case
        if (!isSafe(m, n, startRow, startColumn)) {
            return 1;
        }
        if (dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        if (maxMove == 0) return 0;

        //Recursive Intuition
        int xdir[4] = {1, 0, -1, 0};
        int ydir[4] = {0, -1, 0, 1};
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            ans = (ans % mod + solve(m, n, maxMove - 1, startRow + xdir[i], startColumn + ydir[i]) % mod) % mod;
        }
        return dp[startRow][startColumn][maxMove] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};