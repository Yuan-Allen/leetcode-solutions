/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int u = 0, d = m - 1, l = 0, r = n - 1;
        while (true) {
            for (int j = l; j <= r; ++j) {
                res.emplace_back(matrix[u][j]);
            }
            if (++u > d) {
                break;
            }
            for (int i = u; i <= d; ++i) {
                res.emplace_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }
            for (int j = r; j >= l; --j) {
                res.emplace_back(matrix[d][j]);
            }
            if (--d < u) {
                break;
            }
            for (int i = d; i >= u; --i) {
                res.emplace_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
