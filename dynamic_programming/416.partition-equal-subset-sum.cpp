/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int halfSum = 0;
        int n = nums.size();
        for (int num : nums) {
            halfSum += num;
        }
        if (halfSum % 2 == 1) {
            return false;
        }
        halfSum /= 2;

        vector<bool> dp(halfSum + 1);
        dp[0] = true;
        for (int num : nums) {
            for (int i = halfSum; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[halfSum];
    }
};
// @lc code=end
