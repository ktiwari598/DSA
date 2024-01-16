//
// Created by karan on 1/16/2024.
//
#include<bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:

    unordered_map<int, int> st;
    vector<int> vect;

    RandomizedSet() {

    }

    bool insert(int val) {
        if (st.find(val) == st.end()) {
            vect.push_back(val);
            st[val] = vect.size() - 1;
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (st.find(val) == st.end()) {
            return false;
        }
        swap(vect[st[val]], vect.back());
        st[vect[st[val]]] = st[val];
        vect.pop_back();
        st.erase(val);
        return true;
    }

    int getRandom() {
        return vect[rand() % vect.size()];
    }
};

/*
["RandomizedSet","insert","remove","insert","getRandom","remove","insert","getRandom"]
[[],[1],[2],[2],[],[1],[2],[]]
*/
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */