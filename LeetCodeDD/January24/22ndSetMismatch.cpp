//
// Created by karan on 1/22/2024.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int i = 0;
        while (i < nums.size()) {
            while (nums[i] != i + 1) {
                if (nums[nums[i] - 1] == nums[i]) break;
                swap(nums[i], nums[nums[i] - 1]);
            }
            i++;
        }
        vector<int> vect;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) return {nums[i], i + 1};
        }
        return {};
    }
};