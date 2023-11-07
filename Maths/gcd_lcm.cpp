//
// Created by karan on 11/7/2023.
//

#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (a == b) return a;
    if (a > b) return gcd(a - b, b);
    return gcd(a, b - a);
}

int main() {
    cout << gcd(20, 30) << "\n";
}
