//
// Created by karan on 11/10/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * Program to find if a number is palindrome
 * TC : O(lengthN), SC : O(lengthN)
 */
bool isPalindromeNumbers(int n, int &x) {
    if (n >= 0 && n < 10) return n % 10 == x % 10;
    if (!isPalindromeNumbers(n / 10, x)) return false;
    x /= 10;
    cout << n << " " << x << endl;
    return (n % 10 == x % 10);
}

int main() {
    int n1 = 1331, n2 = 14541, n3 = 123;
    //Creating another number with same value
    int x1 = 1331, x2 = 14541, x3 = 123;
    cout << (isPalindromeNumbers(n1, x1) ? "palindrome number\n" : "not a palindrome number\n");
    cout << (isPalindromeNumbers(n2, x2) ? "palindrome number\n" : "not a palindrome number\n");
    cout << (isPalindromeNumbers(n3, x3) ? "palindrome number" : "not a palindrome number");
}