/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int curPos = 0;
        int maxJump = 0;
        int dest = nums.size() - 1;
        while (maxJump < dest && curPos <= maxJump) {
            maxJump = max(maxJump, curPos + nums[curPos]);
            curPos += 1;
        }
        return maxJump >= dest;
    }
};
// @lc code=end
