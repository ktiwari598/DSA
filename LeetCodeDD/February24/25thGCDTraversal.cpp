//
// Created by karan on 2/25/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    unordered_map<int, vector<int>> index2Prime, prime2Index;

    void dfs(int src, vector<int> &visitedIndex, unordered_map<int, bool> &visitedPrime) {
        if (visitedIndex[src] == true) return;

        visitedIndex[src] = true;
        for (auto prime: index2Prime[src]) {
            if (visitedPrime[prime]) continue;
            visitedPrime[prime] = true;
            for (auto index: prime2Index[prime]) {
                if (visitedIndex[index]) continue;
                dfs(index, visitedIndex, visitedPrime);
            }
        }

    }


    bool canTraverseAllPairs(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            for (int j = 2; j * j <= temp; j++) {
                if (temp % j == 0) {
                    prime2Index[j].push_back(i);
                    index2Prime[i].push_back(j);
                    while (temp % j == 0) {
                        temp = temp / j;
                    }
                }
            }
            if (temp > 1) {
                prime2Index[temp].push_back(i);
                index2Prime[i].push_back(temp);
            }
        }
        int n = nums.size();
        vector<int> visitedIndex(n, 0);
        unordered_map<int, bool> visitedPrime;
        dfs(0, visitedIndex, visitedPrime);
        for (int i = 0; i < nums.size(); i++) {
            if (!visitedIndex[i]) return false;
        }
        return true;
    }
};