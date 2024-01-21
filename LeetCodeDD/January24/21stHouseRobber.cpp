//
// Created by karan on 1/21/2024.
//
#include<bits/stdc++.h>

using namespace std;

int dp[101];

int solve(int cur, vector<int> &nums) {
    //Base Case
    if (cur >= nums.size()) return 0;

    if (dp[cur] != -1) return dp[cur];

    //Recursive Intuition
    int takeCur = nums[cur] + solve(cur + 2, nums);
    int notTakeCur = solve(cur + 1, nums);
    return dp[cur] = max(takeCur, notTakeCur);
}

int rob(vector<int> &nums) {
    int n = nums.size();
    memset(dp, -1, sizeof(dp));
    return solve(0, nums);
}

int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[n - 1];
}