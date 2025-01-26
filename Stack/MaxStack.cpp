//
// Created by Karan Tiwari on 24/01/25.
//

/*
The problem asks us to design a customized stack structure, which is a common Last-In-First-Out (LIFO)
data structure with an added capability of retrieving and removing the maximum element it contains.
This stack should support the following operations:

push(x): Add an element x to the top of the stack.
pop(): Remove the element at the top of the stack and return it.
top(): Return the element at the top of the stack without removing it.
peekMax(): Retrieve the maximum element in the stack without removing it.
popMax(): Retrieve the maximum element in the stack and remove it. If there are multiple instances of the maximum element,
only the top-most one should be removed.
The challenge lies in designing these operations to be time efficient, specifically requiring the top call to be O(1)
and all other calls to be O(log n) complexity.
*/

#include <list>
#include <map>
using namespace std;

list<int> ls;
multimap<int, list<int>::iterator> mp;

void push(int x) {
  ls.push_back(x);
  mp.insert({x, prev(ls.end()));
}

int pop() {
    int lastKey = ls.back();
    ls.pop_back();
    mp.erase(lastKey);
    return lastKey;
}

int top() {
    return ls.back();
}

int peekMax() {
    return mp.rbegin()->first;
}

int popMax() {
    ls.erase(prev(mp.end())->second);
    int maxElement = prev(mp.end())->first;
    mp.erase(prev(mp.end()));
    return maxElement;
}


int main() {
    list<int>push
    return 0;
}