/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
  void backtracking(vector<int> &nums, vector<bool> &used, vector<int> &path,
                    vector<vector<int>> &result) {
    int size = nums.size();

    if (path.size() == size) {
      result.push_back(path);
      return;
    }

    for (int i = 0; i < size; ++i) {
      if (used[i]) {
        continue;
      }
      used[i] = true;
      path.push_back(nums[i]);
      backtracking(nums, used, path, result);
      path.pop_back();
      used[i] = false;
    }
    return;
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    vector<int> path;
    vector<vector<int>> result;
    backtracking(nums, used, path, result);
    return result;
  }
};
// @lc code=end
