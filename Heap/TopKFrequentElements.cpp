//
// Created by karan on 2/8/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it: mp) {
            pq.push({it.second, it.first});
        }
        vector<int> ans;
        while (!pq.empty() && k > 0) {
            auto temp = pq.top();
            pq.pop();
            ans.push_back(temp.second);
            k--;
        }
        return ans;
    }
};