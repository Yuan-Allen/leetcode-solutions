/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, __INT_MAX__);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (c <= i && dp[i - c] != __INT_MAX__) {
                    dp[i] = min(dp[i - c] + 1, dp[i]);
                }
            }
        }
        return dp[amount] == __INT_MAX__ ? -1 : dp[amount];
    }
};
// @lc code=end
