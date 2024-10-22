/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
  bool traversal(TreeNode* cur, long long left_bound, long long right_bound) {
    if (!cur) {
      return true;
    }
    if (cur->left &&
        (cur->left->val >= cur->val || cur->left->val <= left_bound)) {
      return false;
    }
    if (cur->right &&
        (cur->right->val <= cur->val || cur->right->val >= right_bound)) {
      return false;
    }
    return traversal(cur->left, left_bound, cur->val) &&
           traversal(cur->right, cur->val, right_bound);
  }

  TreeNode* pre = nullptr;

  bool isValidBST(TreeNode* root) {
    // return traversal(root, -__LONG_LONG_MAX__ - 1, __LONG_LONG_MAX__);
    if (!root) {
      return true;
    }
    bool result = isValidBST(root->left);
    if (pre && root->val <= pre->val) {
      return false;
    } else {
      pre = root;
    }
    result &= isValidBST(root->right);
    return result;
  }
};
// @lc code=end
