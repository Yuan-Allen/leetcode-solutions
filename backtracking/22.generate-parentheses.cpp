/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
  public:
    void backtracking(int left, int right, string &s, vector<string> &result) {
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }

        if (left > 0) {
            s.push_back('(');
            backtracking(left - 1, right, s, result);
            s.pop_back();
        }
        if (right > left) {
            s.push_back(')');
            backtracking(left, right - 1, s, result);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> result;
        backtracking(n, n, s, result);
        return result;
    }
};
// @lc code=end
