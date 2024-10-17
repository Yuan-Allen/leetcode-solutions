/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] Path Sum
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
  bool traversal(TreeNode* cur, int cur_sum, int target) {
    cur_sum += cur->val;
    bool result = false;
    if (!cur->left && !cur->right && cur_sum == target) {
      return true;
    }
    if (cur->left) {
      result |= traversal(cur->left, cur_sum, target);
    }
    if (!result && cur->right) {
      result |= traversal(cur->right, cur_sum, target);
    }
    return result;
  }
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
      return false;
    }
    return traversal(root, 0, targetSum);
  }
};
// @lc code=end
