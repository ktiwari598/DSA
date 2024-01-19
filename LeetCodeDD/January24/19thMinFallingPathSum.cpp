//
// Created by karan on 1/19/2024.
//

#include<bits/stdc++.h>

using namespace std;


const int M = 1e9 + 7;
//int dp[101][101]; //Using int array, it was giving problem but using vector for the same purpose solved the problem
vector<vector<int>> dp;

bool isSafe(int n, int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

int solve(vector<vector<int>> &matrix, int row, int col) {
    int n = matrix.size();
    if (row == n - 1) return matrix[row][col];
    cout << row << " " << col << endl;

    if (dp[row][col] != M) return dp[row][col];

    int ans = solve(matrix, row + 1, col);
    if (col >= 1) {
        ans = min(ans, solve(matrix, row + 1, col - 1));
    }
    if (col < n - 1) {
        ans = min(ans, solve(matrix, row + 1, col + 1));
    }
    return dp[row][col] = matrix[row][col] + ans;
}

int minFallingPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    cout << n << endl;
    int ans = INT_MAX;
    //memset(dp, M, sizeof(dp));
    dp.assign(n, vector<int>(n, M));
    for (int i = 0; i < n; i++) {
        ans = min(ans, solve(matrix, 0, i));
    }
    return ans;
}

int minFallingPathSum_bottomUp(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[0][i] = matrix[0][i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp = dp[i - 1][j];
            if (j >= 1) {
                temp = min(temp, dp[i - 1][j - 1]);
            }
            if (j < n - 1) {
                temp = min(temp, dp[i - 1][j + 1]);
            }
            dp[i][j] = matrix[i][j] + temp;
        }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main() {
    vector<vector<int>> vect = {};
    cout << minFallingPathSum(vect);
}