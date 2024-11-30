/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
  public:
    vector<int> partitionLabels(string s) {
        int length = s.size();
        int map[26] = {0};
        int start = 0, end = 0;
        vector<int> result;
        for (int i = 0; i < length; ++i) {
            map[s[i] - 'a'] = i;
        }

        for (int i = 0; i < length; ++i) {
            end = max(end, map[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return result;
    }
};
// @lc code=end
