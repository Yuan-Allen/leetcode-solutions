/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int numRow = board.size();
        int numCol = board.size();
        bool rowMap[9][9] = {0};
        bool colMap[9][9] = {0};
        bool boxMap[3][3][9] = {0};

        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int index = board[i][j] - '1';
                if (rowMap[i][index] || colMap[j][index] ||
                    boxMap[i / 3][j / 3][index]) {
                    return false;
                }
                rowMap[i][index] = true;
                colMap[j][index] = true;
                boxMap[i / 3][j / 3][index] = true;
            }
        }

        return true;
    }
};
// @lc code=end
