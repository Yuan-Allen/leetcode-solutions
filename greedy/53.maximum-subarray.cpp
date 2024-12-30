/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int result = nums[0];
        int count = 0;

        for (const int &num : nums) {
            count += num;
            result = max(result, count);
            count = max(count, 0);
        }

        return result;
    }

    int maxSubArrayDP(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};
// @lc code=end
