//
// Created by karan on 2/9/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> divisorCount(n, 1);
        vector<int> prev(n, -1);
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (divisorCount[i] < divisorCount[j] + 1) {
                        divisorCount[i] = divisorCount[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (divisorCount[maxIndex] < divisorCount[i]) {
                maxIndex = i;
            }
        }
        int k = maxIndex;
        vector<int> ans;
        while (k >= 0) {
            ans.push_back(nums[k]);
            k = prev[k];
        }
        return ans;
    }
};