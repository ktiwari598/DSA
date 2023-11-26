//
// Created by karan on 11/26/2023.
//
#include<bits/stdc++.h>

using namespace std;

//Find Indices of 2 sum elements

/**
 * TC : O(2*N)
 * SC : O(N)
 */
vector<int> twoSum_space1(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++) {
        int req = target - nums[i];
        if (mp.find(req) != mp.end() && i != mp[req]) return {i, mp[req]};
    }
    return {};
}

/**
 * TC : O(N)
 * SC : O(N)
 */
vector<int> twoSum_space2(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int req = target - nums[i];
        if (mp.count(req)) {
            return {i, mp[req]};
        }
        mp[nums[i]] = i;
    }
    return {};
}

/**
 * TC : O(NlogN)
 * SC : O(N)
 */
vector<int> twoSum_twoPointer(vector<int> &nums, int target) {
    int i = 0, j = nums.size() - 1;
    vector<pair<int, int>> vect;
    for (int i = 0; i < nums.size(); i++) {
        vect.push_back({nums[i], i});
    }
    sort(vect.begin(), vect.end());
    while (i < j) {
        int temp = vect[i].first + vect[j].first;
        cout << temp << " " << i << " " << j << endl;
        if (temp == target) return {vect[i].second, vect[j].second};
        else if (temp < target) i++;
        else j--;
    }
    return {};
}
