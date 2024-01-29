//
// Created by karan on 1/29/2024.
//
#include<bits/stdc++.h>

using namespace std;

/**
* Return the number of steps to reach the destination from source if only diagonal movement is allowed
 * Like Bishop moves in a chess
 * TC - O(N)
*/

//TC - O(N*N)
void compute(vector<vector<int>> &vect, int srcRow, int srcCol) {
    queue<pair<int, int>> q;
    q.emplace(srcRow, srcCol);
    int count = 0;
    vect[srcRow][srcCol] = 0;

}

bool isSafe(int row, int col, vector<vector<int>> &visited) {
    int m = visited.size(), n = visited[0].size();
    return row >= 0 && row < m && col >= 0 && col < n && visited[row][col] == 0;
}


int solve(string src, string dest) {
    int srcRow = src[0] - '0';
    int srcCol = src[1] - '0';
    int destRow = dest[0] - '0';
    int destCol = dest[1] - '0';

    vector<vector<int>> visited(8, vector<int>(8, 0));
    queue<pair<int, int>> q;
    q.emplace(srcRow, srcCol);

    int xdir[4] = {1, 1, -1, -1};
    int ydir[4] = {1, -1, -1, 1};

    int steps = 0;
    while (!q.empty()) {
        int x = q.size();
        while (x--) {
            auto temp = q.front();
            q.pop();
            if (temp.first == destRow && temp.second == destCol) {
                return steps;
            }
            for (int i = 0; i < 4; i++) {
                int newRow = temp.first + xdir[i];
                int newCol = temp.second + ydir[i];
                while (isSafe(newRow, newCol, visited)) {
                    q.emplace(newRow, newCol);
                    visited[newRow][newCol] = 1;
                    newRow = newRow + xdir[i];
                    newCol = newCol + ydir[i];
                }
            }
        }
        steps++;
    }
    return -1;
}


int main() {
    cout << solve("12", "74") << "\n";
    cout << solve("12", "02") << "\n";
    cout << solve("12", "27") << "\n";
    cout << solve("12", "35") << "\n";
    cout << solve("12", "67") << "\n";
}