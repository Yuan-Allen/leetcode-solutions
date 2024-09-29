/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) {
      return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int level_width = q.size();
      vector<int> cur_level;
      while (level_width-- > 0) {
        TreeNode* cur = q.front();
        q.pop();
        cur_level.push_back(cur->val);
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
      result.push_back(cur_level);
    }

    return result;
  }
};
// @lc code=end
