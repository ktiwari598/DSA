//
// Created by karan on 9/8/2024.
//

/**
 * <a href="https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05">
 * https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05
 * </a>
 */

class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int m = rolls.size();
        int m_sum = accumulate(rolls.begin(), rolls.end(), 0);
        int mean_sum = mean * (m + n) - m_sum;
        vector<int> ans;
        int x = ceil((1.0 * mean_sum) / n);
        if (n > mean_sum || x < 1 || x > 6) return {};
        while (mean_sum > n) {

            if (mean_sum - 6 >= n - 1) {
                mean_sum = mean_sum - 6;
                ans.push_back(6);
            } else {
                ans.push_back(mean_sum - (n - 1));
                mean_sum = n - 1;
            }
            n--;
        }
        while (mean_sum--) {
            ans.push_back(1);
        }
        return ans;
    }
};