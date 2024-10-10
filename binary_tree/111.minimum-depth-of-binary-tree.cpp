/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
  void traversal(TreeNode* cur, int cur_level, int& min_level) {
    if (!cur) {
      return;
    }
    if (!cur->left && !cur->right) {
      min_level = cur_level < min_level ? cur_level : min_level;
    }
    traversal(cur->left, cur_level + 1, min_level);
    traversal(cur->right, cur_level + 1, min_level);
  }

  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int min_level = __INT_MAX__;
    traversal(root, 1, min_level);
    return min_level;
  }
};
// @lc code=end
