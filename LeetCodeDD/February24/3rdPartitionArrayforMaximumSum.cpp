//
// Created by karan on 2/3/2024.
//
#include<bits/stdc++.h>

using namespace std;

int dp[501];

int solve(int cur, vector<int> &arr, int k) {
    //Base Case
    int n = arr.size();
    if (cur >= arr.size()) return 0;

    if (dp[cur] != -1) return dp[cur];

    //Recursive Intuition
    int ans = 0;

    for (int i = 1; i <= k; i++) {
        int maxi = INT_MIN;
        for (int j = cur; j < min(n, cur + i); j++) {
            maxi = max(maxi, arr[j]);
        }
        int temp = (min(n, cur + i) - cur) * maxi;
        //cout << maxi << endl;
        ans = max(ans, temp + solve(cur + i, arr, k));
    }
    return dp[cur] = ans;
}

int partition(vector<int> &arr, int k) {
    memset(dp, -1, sizeof(dp));
    return solve(0, arr, k);
}


int main() {
    vector<int> vect = {1, 15, 7, 9, 2, 5, 10};
    vector<int> vect2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    vector<int> vect3 = {1};
    vector<int> vect4 = {1, 4, 1};
    cout << partition(vect, 3) << "\n";
    cout << partition(vect2, 4) << endl;
    cout << partition(vect3, 1) << endl;
    cout << partition(vect4, 3) << endl;
}