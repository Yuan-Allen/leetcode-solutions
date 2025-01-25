/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int fast = 1;
        int slow = 0;
        int n = nums.size();
        while (fast < n) {
            if (nums[fast] != nums[slow]) {
                nums[++slow] = nums[fast];
            }
            ++fast;
        }
        return slow + 1;
    }
};
// @lc code=end
