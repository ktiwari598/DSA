//
// Created by karan on 2/17/2024.
//
#include<bits/stdc++.h>

using namespace std;

/**
 * Whenever you are thinking in terms of DP, but the constraints are large enough to throw Memory Limit Exceeded,
 * then it is not DP.
 * For larger jumps, we will be using ladders, for shorter jumps we will use bricks.
 * Just iterate the buildings and maintain the top k jumps in priority_queue, whenever the size of priority_queue
 * is > k, then remove the top of the pq, and use bricks for that jump. If total required bricks is > bricks available,
 * then stop there, you cannot go more forward.
 */
int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
    int n = heights.size();
    if (n == 1) return 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int requiredBricks = 0;
    for (int i = 1; i < n; i++) {
        int dif = heights[i] - heights[i - 1];
        if (dif > 0) {
            minHeap.push(dif);
            if (minHeap.size() > ladders) {
                requiredBricks += minHeap.top();
                minHeap.pop();
            }
            if (requiredBricks > bricks) {
                return i - 1;
            }
        }
    }
    return n - 1;
}