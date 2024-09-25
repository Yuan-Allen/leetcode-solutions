/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    traverse(cur->right, res);
    res.push_back(cur->val);
  }

  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    traverse(root, res);
    return res;
  }
};
// @lc code=end
