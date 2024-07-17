/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int umap[26] = {0};
    for (char c : magazine) {
      umap[c - 'a']++;
    }

    for (char c : ransomNote) {
      umap[c - 'a']--;
      if (umap[c - 'a'] < 0) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
