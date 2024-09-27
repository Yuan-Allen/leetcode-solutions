/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
  void recursiveTraverse(TreeNode* cur, vector<int>& res) {
    if (!cur) {
      return;
    }
    recursiveTraverse(cur->left, res);
    res.push_back(cur->val);
    recursiveTraverse(cur->right, res);
  }

  vector<int> inorderTraversalNonRecursive(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> result;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
      if (cur) {
        st.push(cur);
        cur = cur->left;
      } else {
        cur = st.top();
        st.pop();
        result.push_back(cur->val);
        cur = cur->right;
      }
    }
    return result;
  }

  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> result;
    if (root) st.push(root);
    while (!st.empty()) {
      TreeNode* cur = st.top();
      st.pop();
      if (cur) {
        if (cur->right) st.push(cur->right);
        st.push(cur);
        st.push(nullptr);
        if (cur->left) st.push(cur->left);
      } else {
        result.push_back(st.top()->val);
        st.pop();
      }
    }
    return result;
  }
};
// @lc code=end
