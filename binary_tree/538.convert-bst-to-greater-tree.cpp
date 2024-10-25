/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
  int traversal(TreeNode* cur, int sum) {
    if (!cur) {
      return sum;
    }
    cur->val += traversal(cur->right, sum);
    return traversal(cur->left, cur->val);
  }

  TreeNode* convertBST(TreeNode* root) {
    traversal(root, 0);
    return root;
  }
};
// @lc code=end
