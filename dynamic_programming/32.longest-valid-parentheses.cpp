/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
  public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n < 2) {
            return 0;
        }
        vector<int> dp(n, 0); // Defaults to 0
        int maxLength = dp[0];
        for (int i = 1; i < n; ++i) {
            int leftIndex = i - dp[i - 1] - 1;
            if (s[i] == ')' && leftIndex >= 0 && s[leftIndex] == '(') {
                dp[i] = dp[i - 1] + 2 + (leftIndex > 0 ? dp[leftIndex - 1] : 0);
                maxLength = max(maxLength, dp[i]);
            }
        }
        return maxLength;
    }
};
// @lc code=end
