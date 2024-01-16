//
// Created by karan on 12/10/2023.
//
#include<bits/stdc++.h>

using namespace std;

#define loopI(i, start, end) for(int i=start;i<=end;i++)
#define loopD(i, start, end) for(int i=start;i>=end;i--)
#define pii pair<int,int>


bool compare(pii a, pii b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


bool isPossible(int s, unordered_map<int, int> &mp, int maxi) {
    if (maxi >= s) {
        int teamSize = maxi > s ? mp.size() : mp.size() - 1;
        return teamSize >= s;
    }
    return false;
}

void solve(string &str, unordered_map<string, int> &mp, int i, int j, bool flag) {
    //Base Case
    if (j > str.length()) return;
    if (j == str.length()) {
        mp[to_string(str[i])] = true;
        return;
    }
    string st = flag ? str.substr(i) : str[i] + str.substr(j);
    //cout << i << " " << j << " " << st << "\n";
    if (mp.find(st) != mp.end()) {
        return;
    }
    mp[st] = true;
    //Recursive Intuition
    if (flag) {
        solve(str, mp, j, j + 1, true);
        solve(str, mp, i, j + 1, false);
    } else {
        solve(str, mp, i, j + 1, false);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        if (str.length() <= 1) cout << 1 << endl;
        else {
            unordered_map<string, int> mp;
            //mp[str] = true;
            solve(str, mp, 0, 1, true);
            cout << mp.size() << "\n";
        }
    }
}
