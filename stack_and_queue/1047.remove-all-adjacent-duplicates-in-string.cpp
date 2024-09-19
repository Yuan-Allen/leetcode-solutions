/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
 public:
  string removeDuplicates(string s) {
    string result = "";
    for (char c : s) {
      if (!result.empty() && result.back() == c) {
        result.pop_back();
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
};
// @lc code=end
