/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if (n != t.size()) {
            return false;
        }

        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;

        for (int i = 0; i < n; ++i) {
            char sc = s[i], tc = t[i];
            if (smap.count(sc) > 0 && smap[sc] != tc) {
                return false;
            }
            smap[sc] = tc;
            if (tmap.count(tc) > 0 && tmap[tc] != sc) {
                return false;
            }
            tmap[tc] = sc;
        }

        return true;
    }
};
// @lc code=end
