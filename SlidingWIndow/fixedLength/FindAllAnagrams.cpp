//
// Created by karan on 11/10/2023.
//
#include<bits/stdc++.h>

using namespace std;

/**
 *
 * Returns the starting index of anagram in string s
 * TC : O(N)
 * SC : O(1)
 * Main concept is p acts a fixed length window for s
 */
vector<int> findAnagrams(string s, string p) {
    int n = s.length(), k = p.length();
    int i = 0, j = 0;
    int ch1[26] = {0}, ch2[26] = {0};
    for (int x = 0; x < k; x++) {
        ch1[p[x] - 'a']++;
    }
    vector<int> vect;
    while (j < n) {
        ch2[s[j] - 'a']++;
        if (j - i + 1 == k) {
            int count = 0;
            for (int x = 0; x < 26; x++) {
                if (ch1[x] != ch2[x]) break;
                count++;
            }
            if (count == 26) {
                vect.push_back(i);
            }
            ch2[s[i++] - 'a']--;
        }
        j++;
    }
    return vect;
}


int main() {
    string s = "cbaebabacd", p = "abc";
    vector<int> vect = findAnagrams(s, p);
    for (int it: vect) cout << it << " ";
}