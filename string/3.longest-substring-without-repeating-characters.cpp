/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        int slow = 0, fast = 0;
        unordered_set<char> charSet;
        while (fast < n) {
            while (charSet.find(s[fast]) != charSet.end()) {
                charSet.erase(s[slow++]);
            }
            charSet.insert(s[fast]);
            maxLength = max(maxLength, fast - slow + 1);
            ++fast;
        }
        return maxLength;
    }
};
// @lc code=end
