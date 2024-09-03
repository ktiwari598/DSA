//
// Created by karan on 9/3/2024.
//

/**
 * <a href="https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/">
 * https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/</a>
 * @param s
 * @param k
 * @return
 */

//TC - O(N)

int getLucky(string s, int k) {
    int n = s.length();
    int curNumber = 0;
    for (int i = 0; i < n; i++) {
        int pos = s[i] - 'a' + 1;
        //TC  - O(log10(pos))
        while (pos > 0) {
            curNumber += pos % 10;
            pos /= 10;
        }
    }

    while (--k) {
        int digitSum = 0;
        //TC - O(log10(curNumber))
        while (curNumber > 0) {
            digitSum += curNumber % 10;
            curNumber /= 10;
        }
        curNumber = digitSum;
    }
    return curNumber;
}