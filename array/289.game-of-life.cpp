/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        // -1: live to die (1 -> -1)
        // 2: die to live (0 -> 2)

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                // Count live
                int liveCount = 0;
                for (int dx = -1; dx < 2; ++dx) {
                    for (int dy = -1; dy < 2; ++dy) {
                        int x = i + dx, y = j + dy;
                        if (dx == 0 && dy == 0 || x < 0 || x >= m || y < 0 ||
                            y >= n) {
                            continue;
                        }
                        if (board[x][y] == 1 || board[x][y] == -1) {
                            liveCount += 1;
                        }
                    }
                }

                if (board[i][j] == 1) {
                    if (liveCount < 2 || liveCount > 3) {
                        board[i][j] = -1;
                    }
                } else if (liveCount == 3) {
                    board[i][j] = 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
// @lc code=end
