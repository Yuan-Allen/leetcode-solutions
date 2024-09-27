/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    recursiveTraverse(cur->right, res);
    res.push_back(cur->val);
  }

  vector<int> postorderTraversalNonRecursive(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> result;
    if (!root) return result;
    st.push(root);
    while (!st.empty()) {
      TreeNode* cur = st.top();
      st.pop();
      result.push_back(cur->val);
      if (cur->left) st.push(cur->left);
      if (cur->right) st.push(cur->right);
    }
    reverse(result.begin(), result.end());
    return result;
  }

  vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> result;
    if (root) st.push(root);
    while (!st.empty()) {
      TreeNode* cur = st.top();
      st.pop();
      if (cur) {
        st.push(cur);
        st.push(nullptr);
        if (cur->right) st.push(cur->right);
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
