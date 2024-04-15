/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    int table[26] = {0};
    int size = s.size();
    if (t.size() != size) {
      return false;
    }
    for (int i = 0; i < size; ++i) {
      table[s[i] - 'a']++;
      table[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
      if (table[i] != 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
