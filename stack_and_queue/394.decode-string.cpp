/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
  public:
    std::string decodeString(const std::string &s) {
        std::stack<std::pair<int, std::string>> stack;
        std::string res = "";
        int multi = 0;

        for (char c : s) {
            if (c == '[') {
                stack.push({multi, res});
                res = "";
                multi = 0;
            } else if (c == ']') {
                auto [cur_multi, last_res] = stack.top();
                stack.pop();
                std::string tmp = "";
                while (cur_multi--) {
                    tmp += res;
                }
                res = last_res + tmp;
            } else if (isdigit(c)) {
                multi = multi * 10 + (c - '0');
            } else {
                res += c;
            }
        }
        return res;
    }
};
// @lc code=end
