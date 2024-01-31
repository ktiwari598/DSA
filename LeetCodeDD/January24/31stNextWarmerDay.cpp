//
// Created by karan on 1/31/2024.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> vect;
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                vect.push_back(0);
            } else if (temperatures[i] < st.top().first) {
                vect.push_back(st.top().second - i);
            } else {
                while (!st.empty() && st.top().first <= temperatures[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    vect.push_back(0);
                } else vect.push_back(st.top().second - i);
            }
            st.push({temperatures[i], i});
        }
        reverse(vect.begin(), vect.end());
        return vect;
    }
};