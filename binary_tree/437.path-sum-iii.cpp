/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int traversal(TreeNode *cur, int targetSum, long long curSum,
                  unordered_map<long long, int> &prefix) {
        if (!cur) {
            return 0;
        }

        int ret = 0;

        curSum += cur->val;
        ret += prefix[curSum - targetSum];

        prefix[curSum] += 1;
        ret += traversal(cur->left, targetSum, curSum, prefix);
        ret += traversal(cur->right, targetSum, curSum, prefix);
        prefix[curSum] -= 1;

        return ret;
    }

    int pathSum(TreeNode *root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1;
        return traversal(root, targetSum, 0, prefix);
    }
};
// @lc code=end
