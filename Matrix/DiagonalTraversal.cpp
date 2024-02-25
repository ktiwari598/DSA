//
// Created by karan on 2/19/2024.
//

#include<bits/stdc++.h>

using namespace std;

bool isSafe(int row, int col, int m, int n) {
    return row >= 0 && row < m && col >= 0 && col < n;
}

vector<int> solve(int row, int col, int m, int n, vector<vector<int>> &mat) {
    vector<int> vect;
    while (isSafe(row, col, m, n)) {
        vect.push_back(mat[row][col]);
        row = row + 1;
        col = col - 1;
    }
    return vect;
}

vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans;
    bool odd = true;
    for (int i = 0; i < n; i++) {
        int row = 0, col = i;
        vector<int> vect = solve(row, col, m, n, mat);
        if (odd) {
            reverse(vect.begin(), vect.end());
        }
        ans.insert(ans.end(), vect.begin(), vect.end());
        odd = !odd;
    }

    for (int i = 1; i < m; i++) {
        int row = i, col = n - 1;
        vector<int> vect = solve(row, col, m, n, mat);
        if (odd) {
            reverse(vect.begin(), vect.end());
        }
        ans.insert(ans.end(), vect.begin(), vect.end());
        odd = !odd;
    }
    return ans;

}

int main() {
    vector<vector<int>> vect = {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
    vector<int> ans = findDiagonalOrder(vect);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}