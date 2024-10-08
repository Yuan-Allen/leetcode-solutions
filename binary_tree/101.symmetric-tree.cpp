/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
  bool traversal(TreeNode* left_cur, TreeNode* right_cur) {
    if (!left_cur || !right_cur) {
      if (left_cur == right_cur) {
        return true;
      } else {
        return false;
      }
    }

    if (left_cur->val != right_cur->val) {
      return false;
    }

    return traversal(left_cur->left, right_cur->right) &&
           traversal(left_cur->right, right_cur->left);
  }

  bool isSymmetric(TreeNode* root) {
    if (!root) {
      return true;
    }

    return traversal(root->left, root->right);
  }
};
// @lc code=end
