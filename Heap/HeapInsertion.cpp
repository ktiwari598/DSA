//
// Created by karan on 3/14/2024.
//

#include<bits/stdc++.h>

using namespace std;

vector<int> arr;
int k = 3;

void heapify(int N, int i) {
    int leftChildIndex = 2 * i + 1;
    int rightChildIndex = 2 * i + 2;
    int smallest = i;
    if (leftChildIndex < N && arr[leftChildIndex] < arr[smallest]) {
        smallest = leftChildIndex;
    }
    if (rightChildIndex < N && arr[rightChildIndex] < arr[smallest]) {
        smallest = rightChildIndex;
    }
    if (smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(N, smallest);
    }
}

void add(int x) {
    if (arr.size() >= k && x < arr[0]) return;
    if (arr.size() > k) {
        arr[k] = x;
    } else {
        arr.push_back(x);
    }
    int i = arr.size() - 1;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    if (arr.size() > k) {
        swap(arr[arr.size() - 1], arr[0]);
        heapify(arr.size() - 1, 0);
    }
}

void getTopKElement() {
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    add(10);
    add(8);
    add(7);
    getTopKElement();
    add(15);
    add(-1);
    getTopKElement();
    add(0);
    getTopKElement();
    add(20);
    getTopKElement();
}
