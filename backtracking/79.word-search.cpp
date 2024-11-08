/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
  public:
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool backtracking(const vector<vector<char>> &board, const string &word,
                      int x, int y, int k, vector<vector<bool>> &visited) {
        if (board[x][y] != word[k]) {
            return false;
        } else if (k == word.size() - 1) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();
        visited[x][y] = true;
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) {
                continue;
            }
            if (backtracking(board, word, nx, ny, k + 1, visited)) {
                return true;
            }
        }
        visited[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board[0].size(), false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (backtracking(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
