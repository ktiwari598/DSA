//
// Created by karan on 11/7/2023.
//
#include<bits/stdc++.h>

using namespace std;

/**
 * T.C -> O(n)
 * S.C -> O(n) considering recursion stack space
 */
int factorial_recursive(int n) {
    if (n == 1) return 1;
    return n * factorial_recursive(n - 1);
}

/**
 * T.C -> O(n)
 * S.C -> O(1)
 */
int factorial_iterative(int n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = ans * i;
    }
    return ans;
}

/**
 * T.C -> O(n)
 * S.C -> O(n)
 */
int factorial_dp(int n) {
    int dp[n + 1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }
    return dp[n];
}

int multiply(int x, int res[], int res_size) {
    int carry = 0;
    for (int i = 0; i < res_size; i++) {
        int temp = res[i] * x + carry;
        carry = temp / 10;
        res[i] = temp % 10;
    }
    while (carry > 0) {
        res[res_size++] = carry % 10;
        carry /= 10;
    }
    return res_size;
}

/**
 * T.C -> O(n*length(n!))
 * S.C -> O(length(n!)
 */
void factorial_large(int n) {
    int result[10000];
    result[0] = 1;
    int res_size = 1;
    for (int i = 1; i <= n; i++) {
        res_size = multiply(i, result, res_size);
    }
    for (int i = res_size - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << "\n";
}

int main() {
    /*Time function returns the time since the
    Epoch(jan 1 1970). Returned time is in seconds. */
    time_t start, end;
    /* You can call it like this : start = time(NULL);
    in both the way start contain total time in seconds
    since the Epoch. */
    time(&start);

    cout << factorial_recursive(5) << endl;
    factorial_large(1000);

    // Recording end time.
    time(&end);
    // Calculating total time taken by the program.
    auto time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
}