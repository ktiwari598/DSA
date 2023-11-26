//
// Created by karan on 11/26/2023.
//
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> twoSum(vector<int> &nums, long long target, int start) {
    int i = start, j = nums.size() - 1;
    set<vector<int>> st;
    vector<vector<int>> temp;
    while (i < j) {
        long long req = 0ll + nums[i] + nums[j];
        if (req == target) {
            st.insert({nums[i++], nums[j--]});
        } else if (req < target) {
            i++;
        } else j--;
    }
    for (auto it: st) temp.push_back(it);
    return temp;
}

vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k) {
    vector<vector<int>> ans;

    if (start == nums.size()) return ans;
    //Base Case
    if (k == 2) return twoSum(nums, target, start);


    //Recursive Intuition
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i - 1]) continue;
        vector<vector<int>> temp = kSum(nums, target - nums[i], i + 1, k - 1);
        for (auto it: temp) {
            ans.push_back({nums[i]});
            ans.back().insert(ans.back().end(), it.begin(), it.end());
        }
    }
    return ans;
}

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    return kSum(nums, 0ll + target, 0, 4);
}