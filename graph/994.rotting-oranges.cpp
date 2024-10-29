/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int nr = grid.size();
    int nc = grid[0].size();
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int result = 0;
    queue<pair<int, int>> q;
    int count = 0;

    for (int i = 0; i < nr; ++i) {
      for (int j = 0; j < nc; ++j) {
        if (grid[i][j] == 1) {
          count += 1;
        } else if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }

    while (count > 0 && !q.empty()) {
      ++result;
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : directions) {
          int nx = x + dx, ny = y + dy;
          if (nx >= 0 && ny >= 0 && nx < nr && ny < nc && grid[nx][ny] == 1) {
            grid[nx][ny] = 2;
            count -= 1;
            q.push({nx, ny});
          }
        }
      }
    };

    return count ? -1 : result;
  }
};
// @lc code=end
