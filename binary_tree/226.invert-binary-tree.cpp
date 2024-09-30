/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
  void traversal(TreeNode* cur) {
    if (!cur) {
      return;
    }
    TreeNode* tmp = cur->left;
    cur->left = cur->right;
    cur->right = tmp;
    traversal(cur->left);
    traversal(cur->right);
  }
  TreeNode* invertTree(TreeNode* root) {
    traversal(root);
    return root;
  }
};
// @lc code=end
