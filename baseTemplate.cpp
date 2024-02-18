//
// Created by karan on 12/10/2023.
//
#include<bits/stdc++.h>

using namespace std;

#define loopI(i, start, end) for(int i=start;i<=end;i++)
#define loopD(i, start, end) for(int i=start;i>=end;i--)
#define pii pair<int,int>


int solve(vector<string> arr1, vector<string> arr2, int x) {
    int n1 = arr1.size(), n2 = arr2.size();
    if (n1 == 0 || n2 == 0) return 0;
    //cout << n1 << " " << n2 << " " << x << endl;
    unordered_map<int, vector<string>> mp1, mp2;
    for (int i = 0; i < n1; i++) {
        string str = arr1[i];
        //cout << str << " ";
        if (x < str.length()) {
            if (mp1.count(str[x] - '0') == 0) {
                mp1[str[x] - '0'] = vector<string>();
            }
            mp1[str[x] - '0'].push_back(str);
        }
    }
    //cout << endl;
    bool flag = false;
    for (int i = 0; i < n2; i++) {
        string str = arr2[i];
        //cout << str << " ";
        if (x < str.length()) {
            if (mp2.count(str[x] - '0') == 0) {
                mp2[str[x] - '0'] = vector<string>();
            }
            if (mp1.count(str[x] - '0') > 0) flag = true;
            mp2[str[x] - '0'].push_back(str);
        }
    }
//    cout << endl;
//    for (auto it: mp1) {
//        cout << it.first << " : ";
//        for (auto itr: it.second) {
//            cout << itr << " ";
//        }
//        cout << endl;
//    }
//    for (auto it: mp2) {
//        cout << it.first << " : ";
//        for (auto itr: it.second) {
//            cout << itr << " ";
//        }
//        cout << endl;
//    }
//    cout << flag << endl << endl;
    int ans = 0;
    if (flag) {
        for (int i = 0; i < 10; i++) {
            ans = max(ans, 1 + solve(mp1[i], mp2[i], x + 1));
        }
    }
    return ans;
}


int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    vector<string> temp1, temp2;
    for (int i = 0; i < n1; i++) {
        temp1.push_back(to_string(arr1[i]));
    }
    for (int i = 0; i < n2; i++) {
        temp2.push_back(to_string(arr2[i]));
    }
    return solve(temp1, temp2, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> vect1 = {1, 10, 100};
    vector<int> vect2 = {1000};
    vector<int> vect3 = {1, 2, 3};
    vector<int> vect4 = {4, 4, 4};
    vector<int> vect5 = {10, 23, 566};
    vector<int> vect6 = {12, 234, 5664};
    cout << longestCommonPrefix(vect1, vect2) << endl;
    cout << longestCommonPrefix(vect3, vect4) << endl;
    cout << longestCommonPrefix(vect5, vect6) << endl;

}


