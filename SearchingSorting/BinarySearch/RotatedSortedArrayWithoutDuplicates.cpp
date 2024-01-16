//
// Created by karan on 1/16/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int search(vector<int> &nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }


    int search(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1, pivot;
        int n = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[(mid - 1 + n) % n] && nums[mid] < nums[(mid + 1) % n]) {
                pivot = mid;
                break;
            } else if (nums[mid] >= nums[0]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int left = search(nums, 0, pivot - 1, target);
        if (left != -1) return left;
        return search(nums, pivot, n - 1, target);
    }
};