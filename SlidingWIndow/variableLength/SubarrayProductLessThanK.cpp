//
// Created by karan on 11/22/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * TC : O(N)
 *
 */
int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k == 0) return 0;
    int i = 0, j = 0, n = nums.size(), ans = 0;
    int prod = 1;
    while (j < n) {
        if (nums[j] >= k) {
            i = ++j;
            prod = 1;
            continue;
        }
        prod = prod * nums[j];
        while (prod >= k) {
            prod = prod / nums[i++];
        }
        ans += j - i + 1; // add the no. of subarrays
        j++;
    }
    return max(0, ans);
}