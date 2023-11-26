//
// Created by karan on 11/26/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * TC : O(N*N)
 * SC : O(N)
 */
vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    int n = nums.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            int req = nums[i] + nums[j] + nums[k];
            if (req == 0) {
                st.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } else if (req < 0) {
                j++;
            } else k--;
        }
    }
    for (auto it: st) {
        ans.push_back(it);
    }
    return ans;
}