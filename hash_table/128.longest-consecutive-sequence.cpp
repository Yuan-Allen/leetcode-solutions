/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> numSet;
        for (const int &num : nums) {
            numSet.insert(num);
        }
        int longestLength = 0;
        for (const int &num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int i = 1;
                while (numSet.find(num + i) != numSet.end()) {
                    ++i;
                }
                longestLength = max(longestLength, i);
            }
        }
        return longestLength;
    }
};
// @lc code=end
