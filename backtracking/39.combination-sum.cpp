/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
  public:
    void backtracking(const vector<int> &candidates, const int target,
                      int index, int cur_sum, vector<int> &choosen,
                      vector<vector<int>> &result) {
        int size = candidates.size();
        if (index >= size) {
            return;
        }

        for (int i = index; i < size; ++i) {
            int new_sum = cur_sum + candidates[i];
            if (new_sum > target) {
                continue;
            }
            choosen.push_back(candidates[i]);
            if (new_sum == target) {
                result.push_back(choosen);
                // 0 will not appear in candidates, and 2 <= candidates[i] <= 40
                // so no need to backtrack further
            } else {
                backtracking(candidates, target, i, new_sum, choosen, result);
            }
            choosen.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> choosen;
        vector<vector<int>> result;
        backtracking(candidates, target, 0, 0, choosen, result);
        return result;
    }
};
// @lc code=end
