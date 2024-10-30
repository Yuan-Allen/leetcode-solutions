/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> map;
    vector<int> degree(numCourses, 0);
    for (auto edge : prerequisites) {
      map[edge[1]].push_back(edge[0]);
      degree[edge[0]] += 1;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (degree[i] == 0) {
        q.push(i);
      }
    }

    int visited = 0;
    while (!q.empty()) {
      ++visited;
      int cur = q.front();
      q.pop();
      for (auto course : map[cur]) {
        if (--degree[course] == 0) {
          q.push(course);
        }
      }
    }

    return visited == numCourses;
  }
};
// @lc code=end
