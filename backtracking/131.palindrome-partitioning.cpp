/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
    vector<vector<bool>> palindromeTable;

    bool isPalindrome(const string &s, int startIndex, int endIndex) {
        while (startIndex <= endIndex) {
            if (s[startIndex] != s[endIndex]) {
                return false;
            }
            ++startIndex;
            --endIndex;
        }
        return true;
    }

    void backtracking(const string &s, int startIndex, vector<string> &path,
                      vector<vector<string>> &result) {
        int size = s.size();
        if (startIndex >= size) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < size; ++i) {
            // if (isPalindrome(s, startIndex, i)) {
            if (palindromeTable[startIndex][i]) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
                backtracking(s, i + 1, path, result);
                path.pop_back();
            }
        }
    }

  public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> result;

        int size = s.size();
        palindromeTable.assign(size, vector<bool>(size, true));
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                palindromeTable[i][j] =
                    palindromeTable[i + 1][j - 1] && s[i] == s[j];
            }
        }

        backtracking(s, 0, path, result);

        return result;
    }
};
// @lc code=end
