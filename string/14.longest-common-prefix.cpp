/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        string commenPrefix = strs[0];
        int prefixLength = commenPrefix.size();
        int n = strs.size();
        for (int i = 1; i < n; ++i) {
            int length = min(prefixLength, (int)strs[i].size());
            int j = 0;
            while (j < length && commenPrefix[j] == strs[i][j]) {
                ++j;
            }
            prefixLength = j;
            if (prefixLength == 0) { // Early stop
                return commenPrefix.substr(0, 0);
            }
        }
        return commenPrefix.substr(0, prefixLength);
    }
};
// @lc code=end
