//
// Created by karan on 11/15/2023.
//

#include<bits/stdc++.h>

using namespace std;

int cv(char ch) {
    int pos = ch - 'A';
    return pos;
}

int allchars(const int freq1[], const int freq2[]) {
    for (int i = 0; i < 100; i++) {
        if (freq2[i] > 0 && freq1[i] < freq2[i]) return false;
    }
    return true;
}

/**
 * <a href="https://leetcode.com/problems/minimum-window-substring/">
 * Min Window Substring
 * </a> \n
 * Concept : Jab tak T ke sare chars S me nhi aate, increase the window, once all elements came, then decrease the window \n
 * TC : O(length of S)
 */
string minWindow(string s, string t) {
    int i = 0, j = 0, m = s.length(), n = t.length();
    int ans = INT_MAX, start = -1, end = -1;
    int freq1[100] = {0}, freq2[100] = {0};
    for (int i = 0; i < n; i++) {
        freq2[cv(t[i])]++;
    }
    while (j < m) {
        int pos = cv(s[j]);
        freq1[pos]++;
        while (j - i + 1 >= n && allchars(freq1, freq2)) {
            if (j - i + 1 < ans) {
                ans = j - i + 1;
                start = i;
                end = j;
            }
            freq1[cv(s[i])]--;
            i++;
        }
        j++;
    }
    return start == -1 ? "" : s.substr(start, end - start + 1);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
}
