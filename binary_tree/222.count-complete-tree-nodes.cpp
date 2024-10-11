/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }

    TreeNode* left = root->left;
    TreeNode* right = root->right;
    int left_depth = 0;
    int right_depth = 0;
    while (left) {
      left = left->left;
      left_depth += 1;
    }
    while (right) {
      right = right->right;
      right_depth += 1;
    }
    if (left_depth == right_depth) {
      return (2 << left_depth) - 1;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
// @lc code=end
