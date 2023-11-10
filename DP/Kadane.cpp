//
// Created by karan on 11/10/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * TC : O(N)
 * SC : O(1)
 */
int maxSubArray(vector<int> &nums) {
    int temp_max = 0, global_max = INT_MIN;
    for (int num: nums) {
        temp_max += num;
        if (temp_max > global_max) {
            global_max = temp_max;
        }
        if (temp_max < 0) {
            temp_max = 0;
        }
    }
    return global_max;
}


/**
 * TC : O(N)
 * SC : O(1)
 * 3 variables required for getting the max sum subaaray range
 */
vector<int> maxSubArray_range(vector<int> &nums) {
    int temp_max = 0, global_max = INT_MIN, x = -1, y = -1, k = 0;
    for (int i = 0; i < nums.size(); i++) {
        temp_max += nums[i];
        if (temp_max > global_max) {
            y = i;
            x = k;
            global_max = temp_max;
        }
        if (temp_max < 0) {
            k = i + 1;
            temp_max = 0;
        }
    }
    return {x, y};
}

int main() {
    vector<int> nums1 = {10, -1, 2, -7, -8, 6};
    vector<int> nums2 = {-2, -1, -3, -4, -1, -2, -1, -5, -4};
    cout << maxSubArray(nums1) << " " << maxSubArray(nums2) << endl;
    auto vect1 = maxSubArray_range(nums1);
    for (int i = vect1[0]; i <= vect1[1]; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    auto vect2 = maxSubArray_range(nums2);
    for (int i = vect2[0]; i <= vect2[1]; i++) {
        cout << nums1[i] << " ";
    }
}