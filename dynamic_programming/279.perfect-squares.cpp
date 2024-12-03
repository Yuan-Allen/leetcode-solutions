/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
  public:
    int numSquares(int n) {
        vector<int> dp(n + 1, __INT_MAX__);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
};
// @lc code=end
