/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int m = words.size();
        int n = words[0].size();
        int ls = s.size();
        vector<int> result;
        for (int i = 0; i < n && i + m * n - 1 < ls; ++i) {
            unordered_map<string, int> diff;
            for (int j = 0; j < m; ++j) {
                diff[s.substr(i + j * n, n)] += 1;
            }
            for (string &word : words) {
                if (--diff[word] == 0) {
                    diff.erase(word);
                }
            }

            if (diff.empty()) {
                result.emplace_back(i);
            }

            for (int start = i + n; start + m * n - 1 < ls; start += n) {
                string word = s.substr(start - n, n);
                if (--diff[word] == 0) {
                    diff.erase(word);
                }
                word = s.substr(start + (m - 1) * n, n);
                if (++diff[word] == 0) {
                    diff.erase(word);
                }
                if (diff.empty()) {
                    result.emplace_back(start);
                }
            }
        }
        return result;
    }
};
// @lc code=end
