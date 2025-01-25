/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int fast = 2;
        int slow = 2;
        int n = nums.size();
        while (fast < n) {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow++] = nums[fast];
            }
            ++fast;
        }
        return n > 2 ? slow : n;
    }
};
// @lc code=end
