//
// Created by karan on 1/24/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int solve(int cur, vector<string> &arr, string temp) {
        //Base Case
        if (cur == arr.size()) {
            return temp.length();
        }

        //Recursive Intuition
        int ans = INT_MIN;
        unordered_set<char> st;
        string concat = temp + arr[cur];
        bool flag = true;
        for (int i = 0; i < concat.length(); i++) {
            if (st.count(concat[i]) > 0) {
                flag = false;
                break;
            }
            st.insert(concat[i]);
        }
        if (flag) ans = max(ans, solve(cur + 1, arr, temp + arr[cur]));
        ans = max(ans, solve(cur + 1, arr, temp));
        return ans;
    }

    int maxLength(vector<string> &arr) {
        string temp = "";
        return solve(0, arr, temp);
    }
};