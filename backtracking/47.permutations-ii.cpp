/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
    void backtracking(vector<int> &nums, vector<bool> &used, vector<int> &path,
                      vector<vector<int>> &result) {
        int n = nums.size();
        if (path.size() >= n) {
            result.emplace_back(path);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);

        sort(nums.begin(), nums.end());

        backtracking(nums, used, path, result);

        return result;
    }
};
// @lc code=end
