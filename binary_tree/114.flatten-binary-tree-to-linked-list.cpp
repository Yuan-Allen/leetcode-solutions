/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *leftRightMost = cur->left;
                while (leftRightMost->right) {
                    leftRightMost = leftRightMost->right;
                }
                leftRightMost->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }

    void flattenNaive(TreeNode *root) {
        vector<TreeNode *> result;
        stack<TreeNode *> st;
        if (root) {
            st.push(root);
        }

        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            result.emplace_back(cur);
            if (cur->right) {
                st.push(cur->right);
            }
            if (cur->left) {
                st.push(cur->left);
            }
        }

        int size = result.size();
        for (int i = 0; i < size - 1; ++i) {
            result[i]->left = nullptr;
            result[i]->right = result[i + 1];
        }
    }
};
// @lc code=end
