//
// Created by karan on 11/8/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * Auxiliary Space - Temporary space that algorithm takes to complete its work
 * Binomial Theorem (x + y)^n = nΣr=0 nCr x^(n – r) · y^r where, nCr = n!/((n-r)! * r!)   \n
 * C0 + C1 + C2 + … + Cn = 2^n   \n
 * General Term = T[r+1] = nCr x^(n-r) . y^r    \n
 * nCr = (n-1)C(r-1) => including the current chocolate + (n-1)C(r-1) => not including the current chocolate
 * Binomial Coefficients form a pascal triangle
 * 0C0   =>             1
 * 1C0 1C1 =>           1 1
 * 2C0 2C1 2C2 =>       1 2 1
 * 3C0 3C1 3C2 3C3 =>   1 3 3 1
*/

int fact(int n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = ans * i;
    }
    return ans;
}

/**
 * naive approach
 * Time Complexity: O(N)
 * Auxiliary Space: O(1)
 */
int nCr_naive(int n, int r) {
    return fact(n) / (fact(n - r) * fact(r));
}

/**
 * recursive approach
 * Time Complexity: O(2^N)
 * Auxiliary Space: O(N)
 * Memoize this then, TC : O(n*r), SC : O(n*r)
 */
int nCr_recursive(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    return nCr_recursive(n - 1, r - 1) + nCr_recursive(n - 1, r);
}

/**
 * nCr = e^(logn! - logr! - log(n-r)!) => e^[r-1Σi=0 log(n-i) - log(i+1)]
 * Time Complexity: O(r)
 * Space: O(1)
 * Fastest Approach
*/
int nCr_iterative(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    double ans = 0;
    for (int i = 0; i < r; i++) {
        ans += log(n - i) - log(i + 1);
    }
    return (int) round(exp(ans));
}

/**
 * TC : O(n*r)
 * SC : O(n*r)
 */
int nCr_dp_bottomUp(int n, int r) {
    int dp[n + 1][r + 1];
    memset(dp, 1, sizeof(dp));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}

/**
 * TC : O(n*r)
 * SC : O(r)
 * This is space Pascal triangle code with space optimized
 */
int nCr_dp_spaceOptimized(int n, int r) {
    int dp[r + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[r];
}

int main() {
    int n = 30, r = 20;
    cout << "naive: " << nCr_naive(n, r) << endl;
    //cout << "recursive: " << nCr_recursive(n, r) << endl;
    cout << "iterative: " << nCr_iterative(n, r) << endl;
    cout << "dp: " << nCr_dp_bottomUp(n, r) << endl;
    cout << "dp_spaceOptimized: " << nCr_dp_spaceOptimized(n, r) << endl;
    return 0;
}