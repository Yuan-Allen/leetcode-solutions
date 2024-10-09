/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
  int maxDepthLevel(TreeNode* root) {
    if (!root) {
      return 0;
    }

    int max_depth = 0;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
      TreeNode* cur = q.front();
      q.pop();
      if (!cur) {
        ++max_depth;
        if (!q.empty()) {
          // Not the last level
          q.push(nullptr);
        }
      } else {
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
    }
    return max_depth;
  }

  void traversal(TreeNode* cur, int cur_level, int& max_level) {
    if (!cur) {
      return;
    }
    cur_level += 1;
    max_level = cur_level > max_level ? cur_level : max_level;
    traversal(cur->left, cur_level, max_level);
    traversal(cur->right, cur_level, max_level);
  }

  int maxDepth(TreeNode* root) {
    int max_level = 0;
    traversal(root, 0, max_level);
    return max_level;
  }
};
// @lc code=end
