/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    res.push_back(cur->val);
    traverse(cur->left, res);
    traverse(cur->right, res);
  }

  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    traverse(root, res);
    return res;
  }
};
// @lc code=end
