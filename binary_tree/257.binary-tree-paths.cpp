/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
  string pathToString(vector<TreeNode*> path) {
    string s;
    for (TreeNode* node : path) {
      s.append(to_string(node->val));
      s.append("->");
    }
    s.erase(s.end() - 2, s.end());
    return s;
  }

  void traverse(TreeNode* cur, vector<string>& all_paths,
                vector<TreeNode*> cur_path) {
    cur_path.push_back(cur);
    if (!cur->left && !cur->right) {
      all_paths.push_back(pathToString(cur_path));
      return;
    }
    if (cur->left) {
      traverse(cur->left, all_paths, cur_path);
    }
    if (cur->right) {
      traverse(cur->right, all_paths, cur_path);
    }
  }

  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (!root) {
      return result;
    }
    vector<TreeNode*> cur_path;
    traverse(root, result, cur_path);
    return result;
  }
};
// @lc code=end
