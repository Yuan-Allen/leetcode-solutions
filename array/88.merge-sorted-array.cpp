/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, cur = m + n - 1;
        while (i >= 0 && j >= 0) {
            nums1[cur--] = nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
        }
        while (i >= 0) {
            nums1[cur--] = nums1[i--];
        }
        while (j >= 0) {
            nums1[cur--] = nums2[j--];
        }
    }
};
// @lc code=end
