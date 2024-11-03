/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
  public:
    void backtracking(vector<int> &nums, int startIndex, vector<int> &path,
                      vector<vector<int>> &result) {
        int size = nums.size();
        result.push_back(path);
        for (int i = startIndex; i < size; ++i) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1, path, result);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> path;
        vector<vector<int>> result;
        backtracking(nums, 0, path, result);
        return result;
    }
};
// @lc code=end
