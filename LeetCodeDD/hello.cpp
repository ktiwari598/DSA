//
// Created by karan on 2/10/2024.
//
#include<bits/stdc++.h>

using namespace std;

// C++ program for implementation of KMP pattern searching
// algorithm

#include <bits/stdc++.h>

// Fills lps[] for given pattern pat[0..M-1]
void computeLPS(vector<int> &pattern, int m, int LPS[]) {
    int len = 0, i = 1;
    LPS[0] = 0;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            LPS[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = LPS[len - 1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}


int KMPSearch(vector<int> &nums1, vector<int> &pattern) {
    int m = pattern.size(), n = nums1.size();
    vector<int> nums;
    for (int i = 1; i < n; i++) {
        if (nums1[i - 1] < nums1[i]) nums.push_back(1);
        else if (nums1[i - 1] == nums1[i]) nums.push_back(0);
        else if (nums1[i - 1] > nums1[i]) nums.push_back(-1);
    }
    int LPS[m];
    n--;
    computeLPS(pattern, m, LPS);
    for (int i = 0; i < m; i++) {
        cout << i << " " << LPS[i] << endl;
    }

    int j = 0, i = 0, count = 0;
    while (i < n) {

        if (nums[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            //cout << "Match found at index: " << i - j << endl;
            count++;
            j = LPS[j - 1];
        } else if (nums[i] != pattern[j]) {
            if (j != 0) {
                j = LPS[j - 1];
            } else i++;
        }
    }
    return count;
}


int main() {
    vector<int> nums = {480452566, 325227591, 480452566, 480452566, 489436202};
    vector<int> pattern = {1, -1, 0};
    cout << KMPSearch(nums, pattern) << endl;
//    vector<int> nums1 = {1, 2, 3, 4, 5, 6};
//    vector<int> pattern1 = {1, 1};
//    cout << KMPSearch(nums1, pattern1);
}