//
// Created by karan on 1/16/2024.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    /**
     * Main problem is with this test case - [1,0,1,1,1] => here it is difficult to find out left and right sorted array
     * without trimming the array when required
     */

    bool search(vector<int> &nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            //Left Sorted
            if (nums[mid] >= nums[low]) {
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                } else low = mid + 1;
            }
                //Right Sorted
            else {
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else high = mid - 1;
            }
        }
        return false;
    }
};

//2,2,5,5,6,0,0,1,2,3,3,3,3,4,4