//
// Created by karan on 1/20/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;

    vector<int> nsr(vector<int> &arr) {
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> vect;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                vect.push_back(n);
            } else if (st.top().first < arr[i]) {
                vect.push_back(st.top().second);
            } else {
                while (!st.empty() && st.top().first >= arr[i]) {
                    st.pop();
                }
                if (st.empty()) vect.push_back(n);
                else vect.push_back(st.top().second);
            }
            st.push({arr[i], i});
        }
        reverse(vect.begin(), vect.end());
        return vect;
    }

    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        vector<int> vect = nsr(arr);
        int sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = (vect[i] - i) * arr[i] + dp[vect[i]];
            sum = (sum % mod + dp[i] % mod) % mod;
        }
        return sum;
    }
};