//
// Created by karan on 1/24/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isSafe(int row, int col, int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        return row >= 0 && row < m && col >= 0 && col < n && !visited[row][col] && grid[row][col] != 0;
    }

    int dfs(int row, int col, int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
        visited[row][col] = true;

        int xdir[4] = {1, 0, -1, 0};
        int ydir[4] = {0, -1, 0, 1};
        int ans = grid[row][col], temp = -1;
        for (int i = 0; i < 4; i++) {
            if (isSafe(row + xdir[i], col + ydir[i], m, n, grid, visited)) {
                temp = max(temp, dfs(row + xdir[i], col + ydir[i], m, n, grid, visited));
            }
        }
        ans += max(temp, 0);
        visited[row][col] = false;
        return ans;

    }

    int getMaximumGold(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    ans = max(ans, dfs(i, j, m, n, grid, visited));
                }
            }
        }
        return ans;
    }
};