//
// Created by karan on 6/6/2024.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        unordered_map<int, int> mp;
        int n = hand.size();
        if (n % groupSize != 0) return false;
        for (int i: hand) {
            mp[i]++;
        }
        for (int card: hand) {
            int startCard = card;

            //find starting point for this card
            while (mp[startCard - 1]) {
                startCard--;
            }

            //finish all the cards starting from startCard to card
            while (startCard <= card) {
                while (mp[startCard]) {
                    for (int nextCard = startCard; nextCard < startCard + groupSize; nextCard++) {
                        if (!mp[nextCard]) return false;
                        mp[nextCard]--;
                    }
                }
                startCard++;
            }
        }
        return true;
    }
};