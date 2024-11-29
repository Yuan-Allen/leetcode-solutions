/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
  public:
    int jump(vector<int> &nums) {
        int step = 0;
        int curMaxPos = 0;
        int nextMaxPos = 0;
        int dest = nums.size() - 1;

        for (int curPos = 0; curMaxPos < dest; ++curPos) {
            nextMaxPos = max(nextMaxPos, curPos + nums[curPos]);
            if (curPos == curMaxPos) {
                step += 1;
                curMaxPos = nextMaxPos;
            }
        }

        return step;
    }
};
// @lc code=end
