//
// Created by karan on 1/13/2024.
//
class Solution {
public:
    int minSteps(string s, string t) {
        int freq[26] = {0};
        int n = s.length();
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) count += freq[i];
        }

        return count;

    }
};