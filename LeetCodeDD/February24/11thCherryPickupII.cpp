//
// Created by karan on 2/11/2024.
//
#include<bits/stdc++.h>

using namespace std;


class Solution {
public:


    int dp[71][71][71];

    int solve(int row, int first, int second, vector<vector<int>> &grid, int m, int n) {
        //Base Case
        if (!(row >= 0 && row < m && first >= 0 && first < n && second >= 0 && second < n)) {
            return 0;
        }

        if (row == m) return 0;

        int temp = (first == second) ? grid[row][first] : grid[row][first] + grid[row][second];

        if (dp[row][first][second] != -1) return dp[row][first][second];

        //Recursive Intuition
        int ans1 = solve(row + 1, first - 1, second - 1, grid, m, n);
        ans1 = max(ans1, solve(row + 1, first - 1, second, grid, m, n));
        ans1 = max(ans1, solve(row + 1, first - 1, second + 1, grid, m, n));
        ans1 = max(ans1, solve(row + 1, first, second - 1, grid, m, n));
        ans1 = max(ans1, solve(row + 1, first, second, grid, m, n));
        ans1 = max(ans1, solve(row + 1, first, second + 1, grid, m, n));
        ans1 = max(ans1, solve(row + 1, first + 1, second - 1, grid, m, n));
        ans1 = max(ans1, solve(row + 1, first + 1, second, grid, m, n));
        ans1 = max(ans1, solve(row + 1, first + 1, second + 1, grid, m, n));

        return dp[row][first][second] = temp + ans1;
    }

    int cherryPickup(vector<vector<int>> &grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size();
        int n = grid[0].size();

        return solve(0, 0, n - 1, grid, m, n);
    }
};