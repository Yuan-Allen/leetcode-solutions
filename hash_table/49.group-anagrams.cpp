/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            // string key = generateCountKey(str);
            string key = generateSortKey(str);
            map[key].emplace_back(str);
        }

        vector<vector<string>> res;
        for (pair<string, vector<string>> item : map) {
            res.emplace_back(item.second);
        }
        return res;
    }

    string generateCountKey(string str) {
        int count[26] = {0};
        for (char c : str) {
            count[c - 'a'] += 1;
        }
        string key = "";
        for (int i = 0; i < 26; ++i) {
            key += 'a' + i;
            key += count[i];
        }
        return key;
    }

    string generateSortKey(string str) {
        sort(str.begin(), str.end());
        return str;
    }
};
// @lc code=end
