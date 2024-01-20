//
// Created by karan on 1/20/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int search(vector<int> &nums1, vector<int> &nums2, int pos) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = min(nums1[0], nums2[0]);
        int high = max(nums1[n1 - 1], nums2[n2 - 1]);
        while (low < high) {
            int mid = low + (high - low) / 2;
            int place = 0;
            place += upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
            place += upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
            if (place < pos) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }


    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        double ans;
        if (n1 == 0) {
            if (n2 & 1) ans = nums2[n2 / 2];
            else ans = (nums2[n2 / 2] + nums2[n2 / 2 - 1]) / 2.0;
        } else if (n2 == 0) {
            if (n1 & 1) ans = nums1[n1 / 2] / 1.0;
            else ans = (nums1[n1 / 2] + nums1[n1 / 2 - 1]) / 2.0;
        } else {
            int desired, n = n1 + n2;
            if (n & 1) {
                ans = search(nums1, nums2, n / 2 + 1) / 1.0;
            } else {
                int firstEle = search(nums1, nums2, n / 2);
                int secondEle = search(nums1, nums2, n / 2 + 1);
                ans = (firstEle + secondEle) / 2.0;
            }
        }
        return ans;
    }
};