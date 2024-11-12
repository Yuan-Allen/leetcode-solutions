/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
    bool check(int n, int x, int y, const vector<string> &board) {
        for (int i = 0; i < x; ++i) {
            if (board[i][y] == 'Q') {
                return false;
            }
        }

        const vector<pair<int, int>> direction = {{-1, 1}, {-1, -1}};
        for (int i = 1; i < n; ++i) {
            for (auto [dx, dy] : direction) {
                int nx = x + i * dx;
                int ny = y + i * dy;
                if (nx < 0 || ny < 0 || ny >= n) {
                    continue;
                }
                if (board[nx][ny] == 'Q') {
                    return false;
                }
            }
        }
        return true;
    }

    void backtracking(int n, int row, vector<string> &board,
                      vector<vector<string>> &result) {
        if (n == row) {
            result.push_back(board);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (check(n, row, j, board)) {
                board[row][j] = 'Q';
                backtracking(n, row + 1, board, result);
                board[row][j] = '.';
            }
        }
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;

        backtracking(n, 0, board, result);

        return result;
    }
};
// @lc code=end
