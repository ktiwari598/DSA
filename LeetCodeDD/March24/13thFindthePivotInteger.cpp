//
// Created by karan on 3/13/2024.
//

#include<bits/stdc++.h>

using namespace std;

int pivotInteger(int n) {
    int low = 1, high = n;
    int totalSum = (n * (n + 1)) / 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midSum = (mid * (mid + 1)) / 2;
        int rightSum = totalSum - midSum + mid;
        if (midSum == rightSum) {
            return mid;
        } else if (midSum < rightSum) {
            low = mid + 1;
        } else high = mid - 1;
    }
    return -1;
}