/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] Search in a Binary Search Tree
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
  TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* cur = root;
    while (cur) {
      if (cur->val == val) {
        return cur;
      }
      if (cur->val < val) {
        cur = cur->right;
      } else {
        cur = cur->left;
      }
    }
    return cur;
  }
};
// @lc code=end
