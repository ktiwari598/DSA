//
// Created by karan on 11/13/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * TC : O(N)
 * SC : O(N)
 * Main concept is j-i+1 which gives no. of subarrays for that particular j;
 * Eg. 1,2,3,4  i=0, j = 2
 *  j-i+1 = 3 => 3, 2 3, 1 2 3
 */
int solve(vector<int> &nums, int k) {
    int j = 0, n = nums.size(), i = 0;
    int ans = 0;
    unordered_map<int, int> mp;
    while (j < n) {
        mp[nums[j]]++;
        while (mp.size() > k) {
            mp[nums[i]]--;
            if (mp[nums[i]] == 0) mp.erase(nums[i]);
            i++;
        }
        ans += j - i + 1;
        j++;
    }
    return ans;
}


int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    int atMostK = solve(nums, k);
    int atMostKMinusOne = solve(nums, k - 1);
    cout << atMostK - atMostKMinusOne << endl;
}