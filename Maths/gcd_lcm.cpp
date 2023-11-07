//
// Created by karan on 11/7/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * Euclidean subtraction
 */
int gcd1(int a, int b) {
    if (a == b) return a;
    if (a > b) return gcd(a - b, b);
    return gcd1(a, b - a);
}

/**
 * Euclidean division is based on Euclidean subtraction, because at some point, one number becomes factor of other
 * Eg. at some point, a=42, b=14, then b will always be factor of a-b, then after some subtractions a == b.
 */
int gcd2(int a, int b) {
    if (b == 0) return a;
    return gcd2(b, a % b);
}


long long lcm(int a, int b) {
    return (1ll * a * b) / gcd2(a, b);
}

int main() {
    cout << gcd(204, 380) << "\n";
    cout << lcm(204, 308) << "\n";
}
