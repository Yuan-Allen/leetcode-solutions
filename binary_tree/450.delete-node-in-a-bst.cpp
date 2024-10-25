/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
  TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* cur = root;
    TreeNode* pre = nullptr;

    // find
    while (cur && key != cur->val) {
      pre = cur;
      if (key < cur->val) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    if (!cur) {
      return root;
    }

    // simple cases
    if (!cur->left || !cur->right) {
      if (!pre) {
        // The root node is the target node
        root = cur->left ? cur->left : cur->right;
      } else {
        (pre->val > cur->val ? pre->left : pre->right) =
            (cur->left ? cur->left : cur->right);
      }
      delete cur;
      return root;
    }

    // the target node has two children
    // find the left most node in the right subtree
    TreeNode* right = cur->right;
    pre = cur;
    while (right->left) {
      pre = right;
      right = right->left;
    }

    // get the value
    cur->val = right->val;

    // move the left most node found
    (pre->val > right->val ? pre->left : pre->right) = right->right;
    delete right;

    return root;
  }
};
// @lc code=end
