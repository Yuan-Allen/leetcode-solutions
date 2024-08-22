/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
 public:
  void getNext(int* next, string s) {
    int j = 0;
    int length = s.size();
    next[0] = j;
    for (int i = 1; i < length; ++i) {
      while (j > 0 && s[i] != s[j]) {
        j = next[j - 1];
      }
      if (s[i] == s[j]) {
        ++j;
      }
      next[i] = j;
    }
  }

  bool repeatedSubstringPattern(string s) {
    int total_length = s.size();
    vector<int> next(total_length);
    getNext(&next[0], s);
    int common_length = next[total_length - 1];

    if (common_length == 0) {
      return false;
    }

    int diff = total_length - common_length;
    if (total_length % diff == 0) {
      return true;
    } else {
      return false;
    }
  }

  bool repeatedSubstringPatternNaive(string s) {
    string pattern(1, s[0]);
    int total_length = s.size();
    int i = 1;

    while (i <= total_length / 2) {
      if (total_length % i == 0) {
        int times = total_length / i;
        string result = pattern;
        while (times-- > 1) {
          result += pattern;
        }
        if (result == s) {
          return true;
        }
      }
      pattern += s[i];
      ++i;
    }

    return false;
  }
};
// @lc code=end
