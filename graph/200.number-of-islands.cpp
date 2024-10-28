/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
 public:
  void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x,
           int y, const vector<pair<int, int>>& directions) {
    visited[x][y] = true;
    int m = grid.size(), n = grid[0].size();

    for (auto [dx, dy] : directions) {
      int nx = x + dx, ny = y + dy;
      if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] &&
          grid[nx][ny] == '1') {
        dfs(grid, visited, nx, ny, directions);
      }
    }
  }

  // use DFS
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), result = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j] && grid[i][j] == '1') {
          ++result;
          dfs(grid, visited, i, j, directions);
        }
      }
    }
    return result;
  }

  // use BFS
  int numIslandsBFS(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), result = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j] && grid[i][j] == '1') {
          ++result;
          q.push({i, j});
          visited[i][j] = true;

          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
              int nx = x + dx, ny = y + dy;
              if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny] &&
                  grid[nx][ny] == '1') {
                q.push({nx, ny});
                visited[nx][ny] = true;
              }
            }
          }
        }
      }
    }
    return result;
  }
};
// @lc code=end
