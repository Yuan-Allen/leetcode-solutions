/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.size();
        int startIndex = 0, length = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i + l - 1 < n; ++i) {
                int j = i + l - 1;
                dp[i][j] = s[i] == s[j] && (l > 2 ? dp[i + 1][j - 1] : true);
                if (dp[i][j] && l > length) {
                    startIndex = i;
                    length = l;
                }
            }
        }
        return s.substr(startIndex, length);
    }
};
// @lc code=end
