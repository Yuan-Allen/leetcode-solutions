/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0;
        int down = m;
        int row = 0;
        while (up < down) {
            row = up + (down - up) / 2; // To avoid overflow
            if (target == matrix[row][0]) {
                return true;
            } else if (target < matrix[row][0]) {
                down = row;
            } else {
                up = row + 1;
            }
        }
        row = down - 1;
        if (row < 0) {
            return false;
        }
        int left = 0;
        int right = n;
        while (left < right) {
            int col = left + (right - left) / 2;
            if (target == matrix[row][col]) {
                return true;
            } else if (target < matrix[row][col]) {
                right = col;
            } else {
                left = col + 1;
            }
        }
        return false;
    }
};
// @lc code=end
