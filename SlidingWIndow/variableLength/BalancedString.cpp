//
// Created by karan on 11/17/2023.
//

#include<bits/stdc++.h>

using namespace std;

int freq2[26] = {0};

bool isMatching(int freq[]) {
    for (int i = 0; i < 26; i++) {
        if (freq2[i] > 0 && freq[i] < freq2[i]) return false;
    }
    return true;
}

int minWindowSubstringLength(string s) {
    int i = 0, j = 0, n = s.length(), ans = INT_MAX;
    int freq[26] = {0};
    while (j < n) {
        freq[s[j] - 'A']++;
        while (isMatching(freq)) {
            ans = min(ans, j - i + 1);
            freq[s[i++] - 'A']--;
        }
        j++;
    }
    return ans;
}

/**
 * <a href="https://leetcode.com/problems/replace-the-substring-for-balanced-string/solutions/">Balance Substring</a> \n
 *  TC : O(N)
 *  SC : O(26) \n
 *  Main concept is find the min window substring in the main string for the excess chars.
 *  Eg : QRRRQQQWWRRQ, n=12 => 2Q, 2R is extra, so we need to find min substring length in S, which contains all chars of
 *  QQRR
 */
int balancedString(string s) {
    int n = s.length();
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    for (auto it: mp) {
        freq2[it.first - 'A'] = max(0, it.second - n / 4);
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq2[i] != 0) count++;
    }
    return count > 0 ? minWindowSubstringLength(s) : 0;
}

int main() {
    string s = "QRRRQQQWWRRQ";
    cout << balancedString(s) << endl;
}