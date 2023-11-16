//
// Created by karan on 11/16/2023.
//
#include<bits/stdc++.h>

using namespace std;

//------------------------------INSERTION SORT-------------------------------------------

/**
 * TC : O(N^2)
 * SC : O(1) => Inplace sorting
 * Stable sorting
 */
void insertion_sort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
    for (int i: nums) cout << i << " ";
}

//------------------------------MERGE SORT-------------------------------------------

void merge(vector<int> &nums, int l, int mid, int r) {
    int n1 = mid - l + 1, n2 = r - mid;
    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++) {
        arr1[i] = nums[l + i];
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = nums[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            nums[k++] = arr1[i++];
        } else nums[k++] = arr2[j++];
    }
    while (i < n1) {
        nums[k++] = arr1[i++];
    }
    while (j < n2) {
        nums[k++] = arr2[j++];
    }
}

/**
 * TC : O(NlogN)
 * SC : O(N) => Not in place sorting
 * Stable sort
 */
void merge_sort(vector<int> &vect, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge_sort(vect, l, mid);
        merge_sort(vect, mid + 1, r);
        merge(vect, l, mid, r);
    }
}


//------------------------------QUICK SORT-----------------------------------------------

int main() {
    vector<int> vect = {1, 3, 8, 4, 6, 7, 2, 9, 1, 10, 41, 78, 200, 14, 13, 11, 1000, 250};
    insertion_sort(vect);
    merge_sort(vect, 0, vect.size() - 1);
    cout << "\n";
    for (int i: vect) cout << i << " ";
}