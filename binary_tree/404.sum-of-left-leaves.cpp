/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
  int traverse(TreeNode* cur, bool left_flag) {
    if (!cur->left && !cur->right) {
      return left_flag ? cur->val : 0;
    }

    int sum = 0;
    if (cur->left) {
      sum += traverse(cur->left, true);
    }
    if (cur->right) {
      sum += traverse(cur->right, false);
    }
    return sum;
  }

  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return traverse(root, false);
  }
};
// @lc code=end
