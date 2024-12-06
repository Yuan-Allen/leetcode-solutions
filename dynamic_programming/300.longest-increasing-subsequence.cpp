/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        int ret = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end
