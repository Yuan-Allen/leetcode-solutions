/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
  vector<int> result;
  TreeNode* pre = nullptr;
  int max_count = 0;
  int cur_count = 0;

  void traversal(TreeNode* cur) {
    if (!cur) {
      return;
    }

    traversal(cur->left);
    if (pre && cur->val != pre->val) {
      cur_count = 1;
    } else {
      cur_count += 1;
    }
    if (cur_count == max_count) {
      result.push_back(cur->val);
    } else if (cur_count > max_count) {
      result.clear();
      result.push_back(cur->val);
      max_count = cur_count;
    }
    pre = cur;
    traversal(cur->right);
  }

  vector<int> findMode(TreeNode* root) {
    if (!root) {
      return result;
    }
    traversal(root);
    return result;
  }
};
// @lc code=end
