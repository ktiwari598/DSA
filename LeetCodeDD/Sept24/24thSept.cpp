//
// Created by karan on 9/24/2024.
//

/**
<a href = "https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/">
        https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
        </a>
*/

class Solution {
public:

    int solve(vector <string> &vect1, vector <string> &vect2) {
        unordered_set <string> mp;
        for (int i = 0; i < vect1.size(); i++) {
            string cur = "";
            for (int j = 0; j < vect1[i].length(); j++) {
                cur += vect1[i][j];
                mp.insert(cur);
            }
        }
        int ans = 0;
        for (int i = 0; i < vect2.size(); i++) {
            string cur = "";
            for (int j = 0; j < vect2[i].length(); j++) {
                cur += vect2[i][j];
                //cout<<cur<<" "<<endl;
                if (mp.find(cur) == mp.end()) {
                    break;
                }
                ans = max(ans, (int) cur.length());

            }
        }
        return ans;
    }

    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        vector <string> temp1, temp2;
        for (int i = 0; i < arr1.size(); i++) {
            temp1.push_back(to_string(arr1[i]));
        }
        for (int i = 0; i < arr2.size(); i++) {
            temp2.push_back(to_string(arr2[i]));
        }
        return solve(temp1, temp2);
    }

};