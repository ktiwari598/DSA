//
// Created by karan on 1/24/2024.
//
#include<bits/stdc++.h>

using namespace std;


/*
 * TC - O(N) for building the heap tree
 */
void heapify(vector<int> &arr, int N, int cur) {
    int largest = cur;
    int leftChildIndex = 2 * cur + 1;
    int rightChildIndex = 2 * cur + 2;
    if (leftChildIndex < N && arr[leftChildIndex] > arr[largest]) {
        largest = leftChildIndex;
    }
    if (rightChildIndex < N && arr[rightChildIndex] > arr[largest]) {
        largest = rightChildIndex;
    }
    if (largest != cur) {
        swap(arr[largest], arr[cur]);
        heapify(arr, N, largest);
    }
}

/*
 * TC - O(NlogN)
 * SC - O(1), ignoring recursive stack space\\\\\\\\\\
 */
void heapSort(vector<int> &arr) {

    int N = arr.size();

    //Build heap tree
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(arr, N, i);
    }

    for (int i = N - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {
    vector<int> arr = {2, 4, 5, 3, 1, 7};
    heapSort(arr);

}
