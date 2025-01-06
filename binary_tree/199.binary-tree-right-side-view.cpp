/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        TreeNode *cur = root;
        queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            result.emplace_back(cur->val);
        }
        return result;
    }
};
// @lc code=end
