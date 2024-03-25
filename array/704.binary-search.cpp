/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
 public:
  // recursive version
  int search_within(vector<int>& nums, int target, int lower, int upper) {
    if (upper < lower) {
      return -1;
    }

    int index = (lower + upper) / 2;
    int now = nums[index];
    if (now == target) {
      return index;
    }
    if (target < now) {
      return search_within(nums, target, lower, index - 1);
    } else {
      return search_within(nums, target, index + 1, upper);
    }
  }

  int search(vector<int>& nums, int target) {
    int size = nums.size();
    int lower = 0;
    int upper = size - 1;
    int index = 0;
    while (true) {
      if (upper < lower) {
        return -1;
      }
      index = (lower + upper) / 2;
      int now = nums[index];
      if (now == target) {
        return index;
      }
      if (target < now) {
        upper = index - 1;
      } else {
        lower = index + 1;
      }
    }
  }
};
// @lc code=end
