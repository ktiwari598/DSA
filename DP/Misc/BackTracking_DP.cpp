//
// Created by karan on 11/13/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
* <a href="https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring">
 * https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring
 * </a>
 */


int mod = 1e9 + 7;


/**
 * TC : O(26^N)
 * SC : O(N)
 */
int freq[26] = {0};

int solve_backtracking(int index, int n) {
    //Base Case
    if (index == n) {
        if (freq[4] >= 2 && freq[11] >= 1 && freq[19] >= 1) return 1;
        return 0;
    }

    long long temp = 0;
    //Recursive Intuition
    for (int i = 0; i < 26; i++) {
        freq[i]++;
        temp = (temp + solve_backtracking(index + 1, n)) % mod;
        freq[i]--;
    }
    return temp;
}


/**
 * TC : O(N*26)
 * SC : O(N)
 */
int dp[100001][3][2][2];

int solve_dp(int index, int n, int e, int l, int t) {
    //Base Case
    if (index == n) {
        if (e >= 2 && l >= 1 && t >= 1) return 1;
        return 0;
    }

    if (dp[index][e][l][t] != -1) return dp[index][e][l][t];

    //Recursive Intuition
    long long temp = 0;
    for (int i = 0; i < 26; i++) {
        if (i == 4 && e < 2) {
            temp = (temp + solve_dp(index + 1, n, e + 1, l, t)) % mod;
        } else if (i == 11 && l < 1) {
            temp = (temp + solve_dp(index + 1, n, e, l + 1, t)) % mod;
        } else if (i == 19 && t < 1) {
            temp = (temp + solve_dp(index + 1, n, e, l, t + 1)) % mod;
        } else {
            temp = (temp + solve_dp(index + 1, n, e, l, t)) % mod;
        }
    }
    return dp[index][e][l][t] = temp;
}

int stringCount(int n) {
    memset(dp, -1, sizeof(dp));
    return solve(0, n, 0, 0, 0);
}
