//
// Created by karan on 11/15/2023.
//

#include<bits/stdc++.h>

using namespace std;


/**
 * <a href="https://leetcode.com/problems/max-consecutive-ones-iii/">
 *  Max Consecutive Ones III
 * </a>
 * TC : O(N)
 * SC : O(1)
 * Main concept is a window can never have more than k zeroes
 */
int longestOnes(vector<int> &nums, int k) {
    int i = 0, j = 0, n = nums.size(), ans = INT_MIN;
    int freq[2] = {0};
    while (j < n) {
        freq[nums[j]]++;
        while (freq[0] > k) {
            freq[nums[i++]]--;
        }
        ans = max(ans, freq[1] + freq[0]);
        j++;
    }
    return ans;
}

int main() {
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    int maxOnes = longestOnes(nums, k);
    cout << maxOnes << endl;
}