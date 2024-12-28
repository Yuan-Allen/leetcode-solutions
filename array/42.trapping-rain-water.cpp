/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                // leftMax < rightMax
                ans += leftMax - height[left];
                ++left;
            } else {
                // leftMax >= rightMax
                ans += rightMax - height[right];
                --right;
            }
        }

        return ans;
    }
};
// @lc code=end
