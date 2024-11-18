/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
  public:
    vector<int> searchRangeDivide(vector<int> &nums, int target) {
        int size = nums.size();
        if (size == 0) {
            return vector<int>(2, -1);
        }
        int left = 0, right = size;
        int mid = 0;
        vector<int> result;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (nums[mid] != target) {
            result.assign(2, -1);
            return result;
        }

        if (mid == 0 || nums[mid - 1] != target) {
            result.push_back(mid);
        } else {
            int left_left = 0, left_right = mid + 1;
            while (left_left < left_right) {
                int left_mid = left_left + (left_right - left_left) / 2;
                if (nums[left_mid] == target &&
                    (left_mid == 0 || nums[left_mid - 1] != target)) {
                    result.push_back(left_mid);
                    break;
                } else if (nums[left_mid] >= target) {
                    left_right = left_mid;
                } else {
                    left_left = left_mid + 1;
                }
            }
        }

        if (mid == size - 1 || nums[mid + 1] != target) {
            result.push_back(mid);
        } else {
            int right_left = mid, right_right = size;
            while (right_left < right_right) {
                int right_mid = right_left + (right_right - right_left) / 2;
                if (nums[right_mid] == target &&
                    (right_mid == size - 1 || nums[right_mid + 1] != target)) {
                    result.push_back(right_mid);
                    break;
                } else if (nums[right_mid] <= target) {
                    right_left = right_mid + 1;
                } else {
                    right_right = right_mid;
                }
            }
        }

        return result;
    }

    int findTarget(const vector<int> &nums, int target, bool left_flag) {
        int left = 0, right = nums.size();
        int border = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                border = mid;
                if (left_flag) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return border;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int left = findTarget(nums, target, true);
        int right = findTarget(nums, target, false);
        if (left == -1 || right == -1) {
            return {-1, -1};
        } else if (right >= left) {
            return {left, right};
        } else {
            return {-1, -1};
        }
    }
};
// @lc code=end
