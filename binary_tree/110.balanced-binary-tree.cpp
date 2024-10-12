/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
  int getHeight(TreeNode* cur) {
    if (!cur) {
      return 0;
    }

    int left_height = getHeight(cur->left);
    if (left_height < 0) {
      return -1;
    }
    int right_height = getHeight(cur->right);
    if (right_height < 0) {
      return -1;
    }

    if (abs(left_height - right_height) > 1) {
      return -1;
    }

    return max(left_height, right_height) + 1;
  }

  bool isBalanced(TreeNode* root) { return getHeight(root) >= 0; }
};
// @lc code=end
