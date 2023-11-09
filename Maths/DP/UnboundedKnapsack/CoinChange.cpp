//
// Created by karan on 11/9/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * Count number of ways we can make change
 * TC : O(N * sum)
 * SC : O(N * sum)
 */
long long int solve(int cur, int coins[], int N, int sum) {
    //Base Case

    if (sum <= 0) return 1;
    if (cur == N) return 0;

    if (dp[cur][sum] != -1) return dp[cur][sum];

    //Recursive Intuition
    long long int dontTakeIt = solve(cur + 1, coins, N, sum);
    long long int takeIt = 0;
    if (coins[cur] <= sum) {
        takeIt = solve(cur, coins, N, sum - coins[cur]);
    }
    return dp[cur][sum] = takeIt + dontTakeIt;
}

/**
 * Minimum number of coins to make the change
 * TC : O(M * V)
 * SC : O(M * V)
 */
int solve_topDown(int cur, int coins[], int M, int V, vector<vector<int>> &dp) {

    //Base Case
    if (V <= 0) return 0;
    if (cur == M) return INT_MAX - 1;

    if (dp[cur][V] != -1) return dp[cur][V];

    //Recursive Intuition
    int dontTakeIt = solve_topDown(cur + 1, coins, M, V, dp);
    if (coins[cur] <= V) {
        int takeIt = 1 + solve_topDown(cur, coins, M, V - coins[cur], dp);
        return dp[cur][V] = min(takeIt, dontTakeIt);
    }
    return dp[cur][V] = dontTakeIt;
}

/**
 * Minimum number of coins to make the change
 * TC : O(M * V)
 * SC : O(M * V)
 */
int solve_bottomUp(int coins[], int M, int V) {
    int dp[M + 1][V + 1];
    for (int i = 1; i <= M; i++) {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= V; j++) {
        dp[0][j] = INT_MAX - 1;
    }

    for (int j = 1; j <= V; j++) {
        if (j % coins[0] == 0) {
            dp[1][j] = j / coins[0];
        } else {
            dp[1][j] = INT_MAX - 1;
        }
    }

    for (int i = 2; i <= M; i++) {
        for (int j = 1; j <= V; j++) {
            if (coins[i - 1] <= j) {
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[M][V];
}

