/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
  void traverse(TreeNode* cur, vector<int>& res) {
    if (!cur) {
      return;
    }
    traverse(cur->left, res);
    res.push_back(cur->val);
    traverse(cur->right, res);
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    traverse(root, res);
    return res;
  }
};
// @lc code=end
