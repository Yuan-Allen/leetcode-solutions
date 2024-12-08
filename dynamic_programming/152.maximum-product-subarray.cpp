/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        vector<int> dpMin(n);
        vector<int> dpMax(n);
        dpMin[0] = nums[0];
        dpMax[0] = nums[0];
        int ret = nums[0];
        for (int i = 1; i < n; ++i) {
            dpMin[i] =
                min({dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i], nums[i]});
            dpMax[i] =
                max({dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i], nums[i]});
            ret = max(ret, dpMax[i]);
        }
        return ret;
    }
};
// @lc code=end
