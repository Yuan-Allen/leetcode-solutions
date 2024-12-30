/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int n = intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[0] < b[0];
             });

        int curStart = intervals[0][0], curEnd = intervals[0][1];
        bool flag = false;
        for (int i = 0; i < n - 1; ++i) {
            if (intervals[i + 1][0] > curEnd) {
                result.push_back({curStart, curEnd});
                curStart = intervals[i + 1][0];
            }
            curEnd = max(curEnd, intervals[i + 1][1]);
        }
        result.push_back({curStart, curEnd});
        return result;
    }
};
// @lc code=end
