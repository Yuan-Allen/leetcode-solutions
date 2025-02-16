/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution {
  public:
    string convert(string s, int numRows) {
        if (numRows < 2) {
            return s;
        }

        vector<string> rows(numRows);
        string result = "";
        int dir = -1;
        int curRow = 0;
        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                dir = -dir;
            }
            curRow += dir;
        }

        for (string row : rows) {
            result += row;
        }
        return result;
    }
};
// @lc code=end
