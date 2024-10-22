/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
  TreeNode* pre = nullptr;
  int min_abs_diff = __INT_MAX__;
  int getMinimumDifference(TreeNode* root) {
    if (!root) {
      return false;
    }
    getMinimumDifference(root->left);
    if (pre && root->val - pre->val < min_abs_diff) {
      min_abs_diff = root->val - pre->val;
    }
    pre = root;
    getMinimumDifference(root->right);
    return min_abs_diff;
  }
};
// @lc code=end
