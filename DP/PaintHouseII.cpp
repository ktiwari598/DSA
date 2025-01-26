//
// Created by Karan Tiwari on 26/01/25.
//
#include<iostream>
#include<vector>
#include <algorithm>
#include <climits>
using namespace std;

//Can memoize this solution

//TC - O(N * K), N - no. of house, K - no.of colors
int solve(int curHouse, vector<vector<int> >& costs, int prev, int n, int k) {
    //Base Case
    if(curHouse == n) return 0;

    int ans = INT_MAX;
    for(int i=0;i<k;i++) {
        if(i == prev) continue;
        ans = min(ans, costs[curHouse][i] + solve(curHouse+1, costs, i, n, k));
    }
    return ans;
}

int paintHouse(vector<vector<int> >& costs) {
    int n = costs.size();
    int k = costs[0].size();
    int prev = -1;
    return solve(0, costs, prev, n, k);
}


int main() {
    int n = 6, k = 4;
    /*std::vector<std::vector<int> > vect;
    vect.push_back({10, 17, 18, 33});
    vect.push_back({9, 4, 5, 6});
    vect.push_back({7, 39, 23, 56});
    vect.push_back({1, 4, 77, 2});
    vect.push_back({3, 5, 7, 21});
    vect.push_back({23, 43, 56, 22});*/
    vector<vector<int> > vect(n, vector<int>(k, 0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            cin>>vect[i][j];
        }
    }
    cout<<paintHouse(vect)<<endl;
}