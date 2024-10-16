/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
  void traversal(TreeNode* cur, int cur_level, int& left_most_val,
                 int& most_level) {
    if (cur_level > most_level) {
      left_most_val = cur->val;
      most_level = cur_level;
    }
    if (cur->left) {
      traversal(cur->left, cur_level + 1, left_most_val, most_level);
    }
    if (cur->right) {
      traversal(cur->right, cur_level + 1, left_most_val, most_level);
    }
  }

  int findBottomLeftValueRecursive(TreeNode* root) {
    int left_most_val = 0;
    int most_level = 0;
    if (!root) {
      return left_most_val;
    }

    traversal(root, 1, left_most_val, most_level);

    return left_most_val;
  }

  int findBottomLeftValue(TreeNode* root) {
    int left_most_val = 0;
    if (!root) {
      return left_most_val;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int width = q.size();
      for (int i = 0; i < width; ++i) {
        TreeNode* cur = q.front();
        q.pop();
        if (i == 0) {
          left_most_val = cur->val;
        }
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
    }
    return left_most_val;
  }
};
// @lc code=end
