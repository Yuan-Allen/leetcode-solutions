/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
  public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        while (left < right) {
            res = max(res, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        return res;
    }
};
// @lc code=end
