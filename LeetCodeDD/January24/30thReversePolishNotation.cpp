//
// Created by karan on 1/30/2024.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                if (!st.empty()) {
                    int second = st.top();
                    st.pop();
                    int first = st.top();
                    st.pop();
                    if (tokens[i] == "+") {
                        st.push(first + second);
                    } else if (tokens[i] == "-") {
                        st.push(first - second);
                    } else if (tokens[i] == "*") {
                        st.push(first * second);
                    } else if (tokens[i] == "/") {
                        st.push(first / second);
                    }
                }
            } else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};