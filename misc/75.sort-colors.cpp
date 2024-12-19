/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int redPos = 0;
        int bluePos = nums.size() - 1;
        int tmp = 0;
        for (int i = 0; i <= bluePos; ++i) {
            while (i <= bluePos && nums[i] == 2) {
                tmp = nums[bluePos];
                nums[bluePos] = 2;
                nums[i] = tmp;
                bluePos -= 1;
            }
            if (nums[i] == 0) {
                tmp = nums[redPos];
                nums[redPos] = 0;
                nums[i] = tmp;
                redPos += 1;
            }
        }
    }
};
// @lc code=end
