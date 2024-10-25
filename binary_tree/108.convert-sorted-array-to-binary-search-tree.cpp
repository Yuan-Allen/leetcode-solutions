/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
  TreeNode* buildTree(vector<int>& nums, int left, int right) {
    if (left >= right) {
      return nullptr;
    }
    // we can use `int mid = left + ((right - left) / 2);` instead to avoid
    // int overflow.
    int mid = (left + right) / 2;
    TreeNode* cur = new TreeNode(nums[mid]);
    cur->left = buildTree(nums, left, mid);
    cur->right = buildTree(nums, mid + 1, right);
    return cur;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildTree(nums, 0, nums.size());
  }
};
// @lc code=end
