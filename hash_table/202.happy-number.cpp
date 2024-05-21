/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> visited;
    int cur = n;
    while (visited.find(cur) == visited.end()) {
      visited.insert(cur);
      int sum = 0;
      while (cur > 0) {
        sum += (cur % 10) * (cur % 10);
        cur = cur / 10;
      }
      if (sum == 1) {
        return true;
      }
      cur = sum;
    }
    return false;
  }
};
// @lc code=end
