//
// Created by karan on 2/12/2024.
//
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int e;
    int c;
};

class Solution {
public:

    struct Node {
        int e;
        int c;
    };

    int majorityElement(vector<int> &nums) {
        int n = nums.size(), k = 2;
        struct Node container[k - 1];
        //Initialise the container with count  as 0
        for (int i = 0; i < k - 1; i++) {
            container[i].c = 0;
        }

        //Traverse all the elements and increase the count if already present in container
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < k - 1; j++) {
                if (container[j].e == nums[i]) {
                    container[j].c += 1;
                    break;
                }
            }

            //If the element is not already present in the container, then find the first empty container
            //and insert the element there
            int l;
            if (j == k - 1) {
                for (l = 0; l < k - 1; l++) {
                    if (container[l].c == 0) {
                        container[l].e = nums[i];
                        container[l].c = 1;
                        break;
                    }
                }
                if (l == k - 1) {
                    for (int x = 0; x < k - 1; x++) {
                        container[x].c -= 1;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < k - 1; i++) {
            int count = 0;
            for (int j = 0; j < n && container[i].c > 0; j++) {
                if (container[i].e == nums[j]) count++;
            }
            if (count > n / k) ans.push_back(container[i].e);
        }
        return ans[0];

    }
};

int main() {
    vector<int> nums = {1, 3, 1, 1, 4, 1, 1, 5, 1, 1, 6, 2, 2};
    cout << majorityElement(nums) << endl;
}