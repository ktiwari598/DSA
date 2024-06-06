//
// Created by karan on 12/10/2023.
//
#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/tree_policy.hpp>

#define loopI(i, start, end) for(int i=start;i<=end;i++)
#define loopD(i, start, end) for(int i=start;i>=end;i--)
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int median(vector<int> arr, int start) {
    int n = arr.size() - start;
    if (n & 1) {
        return arr[start + n / 2];
    }
    return ceil((arr[start + n / 2 - 1] + arr[start + n / 2]) / 2.0);
}

int solve(vector<int> arr, int start, int k) {

    cout << start << " ";
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << " ";
    cout << endl;

    if (start >= arr.size()) return 0;

    if (arr[arr.size() - 1] - arr[start] <= k) return 0;

    //cout << start << endl;
    vector<int> arr1 = arr;
    int n = arr1.size();
    int med = median(arr, start);
    //cout << med << endl;
    int temp = arr1[n - 1];
    if (arr1[n - 1] == med) return 0;

    arr1[n - 1] = med;
    sort(arr1.begin(), arr1.end());

//    for (int i = 0; i < arr1.size(); i++) cout << arr1[i] << " ";
//    cout << endl;

    int first = temp - med + solve(arr1, start, k);
    int second = arr[start] + solve(arr, start + 1, k);
    //cout << first << " " << second << endl;
    return min(first, second);
}


int minimumDeletions(string word, int k) {
    vector<int> freq(26, 0);
    for (char ch: word) {
        freq[ch - 'a']++;
    }

    sort(freq.begin(), freq.end());
    vector<int> res;
    for (int i = 0; i <= 25; i++) {
        if (freq[i] > 0) {
            res.push_back(freq[i]);
        }
    }
//    for (int i: res) cout << i << " ";
//    cout << endl;
    return solve(res, 0, k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //vector<int> vect = {};
    string str1 = "dabdcbdcdcd";
    string str2 = "aabcaba";
    //cout << minimumDeletions(str1, 2) << endl;
    cout << minimumDeletions(str2, 0) << endl;
}


