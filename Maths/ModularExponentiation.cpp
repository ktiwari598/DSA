//
// Created by karan on 11/8/2023.
//
#include<bits/stdc++.h>

using namespace std;

/**
 * TC : O(logy)
 * SC : O(1)
 */
int power_iterative(int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y & 1) ans = ans * x;
        x = x * x;
        y = y >> 1;
    }
    return ans;
}

/**
 * TC : O(logy)
 * SC : O(logy)
 */
float power(int x, int y) {
    if (y == 0) return 1;
    float temp = power(x, y / 2);
    if (y % 2 == 0) return temp * temp;
    else {
        if (y > 0) return temp * temp * x;
        return (temp * temp) / x; // for negative y, (temp * temp)/x;
    }
}

/**
 * x^y = x^(y/2) * x^(y/2) if y%2==0  \n
 * x^y = x * x^(y/2) * x^(y/2) if y%2==1
 */
int powerM(int x, int y, int mod) {
    if (y == 0) return 1;
    int temp = powerM(x, y / 2, mod);
    if (y & 1) return ((temp * temp) % mod * x) % mod;
    return (temp * temp) % mod;
}

/**
 * Modular multiplicative inverse
 * (A * x)%M = 1 => x is modular multiplicative inverse of A
 * The multiplicative inverse of “A modulo M” exists if and only if A and M are relatively prime (i.e. if gcd(A, M) = 1)
 * The below method is only valid when M is a prime number
 * When M is prime, we can use Fermat little Theorem, (a^(m-1))%m = 1
 * (a * a^(m-2))%m = 1, (a.x)%m = 1 => x = (a^(m-2))%m
 */
int modular_multiplicative_inverse(int x, int m) {
    if (__gcd(x, m) == 1) {
        cout << powerM(x, m - 2, m) << endl;
    } else {
        cout << "No modular multiplicative inverse exist as gcd(" << x << "," << m << ") is not 1";
    }
}

int main() {
    cout << power_iterative(20, 10) << endl;
    cout << power(20, 10) << endl;
    cout << powerM(34, 41, 20) << endl;
    cout << modular_multiplicative_inverse(3, 11);
}