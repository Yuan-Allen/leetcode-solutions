/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
  public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int paperNum = 0;
        vector<int> counter(n + 1, 0); // 0 to n
        for (int c : citations) {
            counter[min(n, c)] += 1;
        }
        for (int i = n; i >= 0; --i) {
            paperNum += counter[i];
            if (paperNum >= i) {
                return i;
            }
        }
        return 0;
    }
};
// @lc code=end
