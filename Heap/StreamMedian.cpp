//
// Created by karan on 11/16/2023.
//

#include<bits/stdc++.h>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<>> min_heap;

/**
 * Main Concept : Divide the stream into 2 part, one maxHeap and other minHeap
 * Eg: 10 5 20 15 => maxHeap = 5 10, minHeap = 15 20
 * Median = (maxHeap.top() + minHeap.top())/2 = (10 + 15)/2
 * TC : O(logN)
 */
void addNum(int num) {
    if (max_heap.empty() || num <= max_heap.top()) {
        max_heap.push(num);
    } else min_heap.push(num);
    int n1 = max_heap.size(), n2 = min_heap.size();
    if (n1 > n2 + 1) {
        min_heap.push(max_heap.top());
        max_heap.pop();
    } else if (n2 > n1 + 1) {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
}

/**
 * TC : O(logN)
 */
double findMedian() {
    int n1 = max_heap.size(), n2 = min_heap.size();
    if (n1 == n2) {
        return (max_heap.top() + min_heap.top()) / 2.0;
    } else if (n1 > n2) return max_heap.top();
    return min_heap.top();
}

int main() {
    addNum(10);
    addNum(5);
    addNum(20);
    cout << findMedian() << endl;
    addNum(15);
    cout << findMedian() << endl;
}