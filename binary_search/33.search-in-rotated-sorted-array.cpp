/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size();
        int first = nums[0];
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                if (first <= target &&
                    first >= nums[mid]) { // first ... target ... nums[mid]
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else {
                if (target < first &&
                    nums[mid] >= first) { // first ... nums[mid] ... target
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
        }

        return -1;
    }
};
// @lc code=end
