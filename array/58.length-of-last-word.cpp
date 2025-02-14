/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        int length = 0;
        while (s[index] == ' ') {
            --index;
        }

        while (index >= 0 && s[index] != ' ') {
            length += 1;
            --index;
        }

        return length;
    }
};
// @lc code=end
