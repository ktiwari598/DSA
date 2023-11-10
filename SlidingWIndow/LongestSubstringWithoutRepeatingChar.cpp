//
// Created by karan on 11/10/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * TC : O(N)
 * SC : O(N)
 */
int lengthOfLongestSubstringWithoutRepeatingChar(string s) {
    int i = 0, j = 0, n = s.length();
    int maxi = 0;
    unordered_map<char, int> umap;
    while (j < n) {
        if (umap.find(s[j]) != umap.end()) {
            int x = umap[s[j]];
            if (x >= i) {
                i = x + 1;
            }
        }
        maxi = max(maxi, j - i + 1);
        umap[s[j]] = j;
        j++;
    }
    return maxi;
}