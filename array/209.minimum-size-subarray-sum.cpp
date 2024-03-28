/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int left = 0;
    int right = 0;
    int n = nums.size();
    int min_len = n + 1;
    while (right < n) {
      sum += nums[right];

      if (sum >= target) {
        while (sum - nums[left] >=
               target) {  // if target can be zero, the condition should be
                          // (left <= right && sum - nums[left] >= target
          sum -= nums[left];
          left++;
        }
        if (right - left + 1 < min_len) {
          min_len = right - left + 1;
        }
      }
      right++;
    }

    return min_len > n ? 0 : min_len;
  }
};
// @lc code=end
