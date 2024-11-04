/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
  public:
    const vector<string> mapping = {"abc", "def",  "ghi", "jkl",
                                    "mno", "pqrs", "tuv", "wxyz"};

    void backtracking(string &digits, int startIndex, string &path,
                      vector<string> &result) {
        int size = digits.size();
        if (startIndex >= size) {
            if (size > 0) {
                result.push_back(path);
            }
            return;
        }

        string chars = mapping[digits[startIndex] - '2'];
        int numChars = chars.size();

        for (int i = 0; i < numChars; ++i) {
            path.push_back(chars[i]);
            backtracking(digits, startIndex + 1, path, result);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string path;
        backtracking(digits, 0, path, result);
        return result;
    }
};
// @lc code=end
