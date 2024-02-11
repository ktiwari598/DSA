//
// Created by karan on 2/11/2024.
//
#include<bits/stdc++.h>

using namespace std;

void computeLPS(string &pattern, int m, int LPS[]) {
    int len = 0, i = 1;
    LPS[0] = 0;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            LPS[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = LPS[len - 1];
            } else {
                LPS[i] = 0;
                i++;
            }
        }
    }
}


void KMPSearch(string text, string pattern) {
    int m = pattern.length(), n = text.length();

    int LPS[m];
    computeLPS(pattern, m, LPS);
    for (int i = 0; i < m; i++) {
        cout << i << " " << LPS[i] << endl;
    }

    int j = 0, i = 0;
    while (i < n) {

        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Match found at index: " << i - j << endl;
            j = LPS[j - 1];
        } else if (text[i] != pattern[j]) {
            if (j != 0) {
                j = LPS[j - 1];
            } else i++;
        }
    }

}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
}
