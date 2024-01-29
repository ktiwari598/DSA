//
// Created by karan on 1/29/2024.
//

#include<bits/stdc++.h>

using namespace std;

class MyQueue {
public:

    stack<int> st1, st2;
    int front;

    MyQueue() {

    }

    /**
     * While pushing, use st2 for maintaining the first element at the top of st1
     */
    void push2(int x) {
        if (st1.empty()) {
            st1.push(x);
            return;
        }
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop2() {
        int ans = st1.top();
        st1.pop();
        return ans;
    }

    int peek2() {
        return st1.top();
    }

    bool empty2() {
        return st1.empty();
    }

    /**
     * Intuition - Push into st1, pop from st2
     */
    void push1(int x) {
        if (st1.empty()) front = x;
        st1.push(x);
    }

    int pop1() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = st2.top();
        st2.pop();
        return ans;
    }

    int peek1() {
        if (st2.empty()) return front;
        return st2.top();
    }

    bool empty1() {
        return st1.empty() && st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */