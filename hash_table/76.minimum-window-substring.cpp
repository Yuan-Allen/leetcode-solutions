/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
  public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cmap;
        int tn = t.size(), sn = s.size();
        int lack = 0;
        int minLenth = __INT_MAX__, minIndex = 0;

        for (int i = 0; i < tn; ++i) {
            --cmap[t[i]];
        }

        lack = cmap.size();

        for (int left = 0, right = 0; right < sn; ++right) {
            if (++cmap[s[right]] == 0) {
                --lack;
            }
            while (cmap[s[left]] > 0) {
                --cmap[s[left]];
                ++left;
            }
            if (lack <= 0 && right - left + 1 < minLenth) {
                minLenth = right - left + 1;
                minIndex = left;
            }
        }

        return minLenth == __INT_MAX__ ? "" : s.substr(minIndex, minLenth);
    }
};
// @lc code=end
