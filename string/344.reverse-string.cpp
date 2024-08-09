/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
 public:
  void reverseString(vector<char>& s) {
    char tmp;

    for (int left = 0, right = s.size() - 1; left < right; left++, right--) {
      tmp = s[left];
      s[left] = s[right];
      s[right] = tmp;
    }
  }
};
// @lc code=end
