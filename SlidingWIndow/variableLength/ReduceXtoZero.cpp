//
// Created by karan on 11/22/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * TC : O(N)
 * Main Concept : Dont find minimum operations for reducing x to 0. Instead find the maximum length subarray whose sum is equal to SUM(array) - x;
 */
int solve(vector<int> &nums, int k) {
    if (k <= 0) return k;
    int n = nums.size(), i = 0, j = 0;
    int sum = 0, ans = -1;
    while (j < n) {
        sum += nums[j];
        while (sum >= k) {
            if (sum == k) {
                ans = max(ans, j - i + 1);
            }
            sum -= nums[i++];
        }
        j++;
    }
    return ans;
}

int minOperations(vector<int> &nums, int x) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int k = sum - x;
    int ans = solve(nums, k);
    return ans < 0 ? -1 : n - ans;
}