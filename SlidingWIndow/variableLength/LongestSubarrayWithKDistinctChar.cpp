//
// Created by karan on 11/10/2023.
//

#include<bits/stdc++.h>

using namespace std;

/**
 * longest subarray with k distinct character
 * TC : O(N)
 * SC : O(N)
 * Jab tak map ka size K se kam, tab tak bas insert karo and ans check karo, jaise hi map ka size K se jyada hoye
 * starting se map ka size karo
 */
int totalFruit(vector<int> &fruits) {
    int i = 0, j = 0, n = fruits.size(), ans = 0;
    unordered_map<int, int> mp;
    int k = 2;
    while (j < n) {
        mp[fruits[j]]++;
        while (mp.size() > k) {
            mp[fruits[i]]--;
            if (mp[fruits[i]] == 0) {
                mp.erase(fruits[i]);
            }
            i++;
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main() {
    vector<int> vect = {1, 2, 3, 2, 2, 4, 4, 4};
    cout << totalFruit(vect);
}