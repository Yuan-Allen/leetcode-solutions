/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int traverse(TreeNode *cur, int &maxLengh) {
        if (cur == nullptr) {
            return 0;
        }

        int left = traverse(cur->left, maxLengh);
        int right = traverse(cur->right, maxLengh);
        maxLengh = max(maxLengh, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        int maxLength = 0;
        traverse(root, maxLength);
        return maxLength;
    }
};
// @lc code=end
