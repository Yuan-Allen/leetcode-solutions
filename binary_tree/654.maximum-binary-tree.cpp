/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* traversal(vector<int>& nums, int left_index, int right_index) {
    if (right_index - left_index == 1) {
      return new TreeNode(nums[left_index]);
    }

    int max_index = left_index;
    int max_val = -1;
    for (int i = left_index; i < right_index; ++i) {
      if (nums[i] > max_val) {
        max_val = nums[i];
        max_index = i;
      }
    }
    TreeNode* cur = new TreeNode(max_val);
    if (max_index > left_index) {
      cur->left = traversal(nums, left_index, max_index);
    }
    if (right_index > max_index + 1) {
      cur->right = traversal(nums, max_index + 1, right_index);
    }
    return cur;
  }
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return traversal(nums, 0, nums.size());
  }
};
// @lc code=end
