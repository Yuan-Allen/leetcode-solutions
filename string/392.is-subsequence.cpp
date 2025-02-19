/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
  public:
    bool isSubsequence(string s, string t) {
        int sp = 0, tp = 0;
        int sSize = s.size(), tSize = t.size();
        while (sp < sSize && tp < tSize) {
            if (s[sp] == t[tp]) {
                ++sp;
            }
            ++tp;
        }
        return sp >= sSize;
    }
};
// @lc code=end
