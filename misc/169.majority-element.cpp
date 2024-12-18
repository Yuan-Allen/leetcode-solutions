/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (candidate == num) {
                count += 1;
            } else {
                count -= 1;
            }
        }
        return candidate;
    }
};
// @lc code=end
