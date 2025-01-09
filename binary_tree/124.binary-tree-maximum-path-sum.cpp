/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int traversal(TreeNode *cur, int &maxSum) {
        if (!cur) {
            return 0;
        }

        int left = traversal(cur->left, maxSum);
        int right = traversal(cur->right, maxSum);
        maxSum = max(cur->val + left + right, maxSum);
        return max(0, cur->val + max(left, right));
    }

    int maxPathSum(TreeNode *root) {
        int maxSum = -__INT_MAX__ - 1;
        traversal(root, maxSum);
        return maxSum;
    }
};
// @lc code=end
