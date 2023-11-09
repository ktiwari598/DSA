//
// Created by karan on 11/9/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * AP , a+(n-1)d, SUM = n/2[2a + (n-1)d]
 * GP, ar^(n-1), SUM = a(r^n -1)/(r-1)
 */

/**
 * T.C : O(sqrtN)
 * S.C : O(sqrtN) => can be made O(1) if we loop till sqrtN and then retrace back to 1
 */
int factors(int n) {
    vector<int> ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) cout << i << " ";
            else {
                cout << i << " ";
                ans.push_back(n / i);
            }
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
}

/**
 * Print all prime factors
 * TC : O(sqrtN)
 * SC : O(1)
 */
void prime_factors(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 2) cout << n << endl;
}


int main() {
    cout << factors(100) << endl;
    prime_factors(315);
}