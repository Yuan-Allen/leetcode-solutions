/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        int slow = 0;
        for (int fast = slow; fast < n; ++fast) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        while (slow < n) {
            nums[slow++] = 0;
        }
    }
};
// @lc code=end
