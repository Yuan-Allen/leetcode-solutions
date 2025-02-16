/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution {
  public:
    unordered_map<char, int> hmap = {{'I', 1},   {'V', 5},   {'X', 10},
                                     {'L', 50},  {'C', 100}, {'D', 500},
                                     {'M', 1000}};

    int romanToInt(string s) {
        int n = s.size();
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            int value = hmap[s[i]];
            if (i + 1 < n && value < hmap[s[i + 1]]) {
                ret -= value;
            } else {
                ret += value;
            }
        }
        return ret;
    }
};
// @lc code=end
