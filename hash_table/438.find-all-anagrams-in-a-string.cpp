/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
  public:
    vector<int> findAnagrams(string s, string p) {
        int pn = p.size();
        int sn = s.size();
        vector<int> res;
        if (sn < pn) {
            return res;
        }
        int diff = 0;
        unordered_map<char, int> cmap;
        for (int i = 0; i < pn; ++i) {
            --cmap[p[i]];
            ++cmap[s[i]];
        }
        for (auto item : cmap) {
            if (item.second != 0) {
                ++diff;
            }
        }
        if (diff == 0) {
            res.emplace_back(0);
        }

        for (int i = 0; i < sn - pn; ++i) {
            // remove s[i] from the window
            if (cmap[s[i]] == 1) {
                --diff;
            } else if (cmap[s[i]] == 0) {
                ++diff;
            }
            cmap[s[i]] -= 1;

            // add s[i+pn] to the window
            if (cmap[s[i + pn]] == -1) {
                --diff;
            } else if (cmap[s[i + pn]] == 0) {
                ++diff;
            }
            cmap[s[i + pn]] += 1;

            if (diff == 0) {
                res.emplace_back(i + 1);
            }
        }

        return res;
    }
};
// @lc code=end
