/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
  TreeNode* traversal(vector<int>& inorder, vector<int>& postorder,
                      int inorder_begin, int inorder_end, int postorder_begin,
                      int postorder_end) {
    if (postorder_begin == postorder_end) {
      return nullptr;
    }
    int cur_val = postorder[postorder_end - 1];
    TreeNode* cur = new TreeNode(cur_val);
    if (postorder_begin + 1 < postorder_end) {  // early stop
      for (int i = inorder_begin; i < inorder_end; ++i) {
        if (inorder[i] == cur_val) {
          cur->left =
              traversal(inorder, postorder, inorder_begin, i, postorder_begin,
                        postorder_begin + i - inorder_begin);
          cur->right =
              traversal(inorder, postorder, i + 1, inorder_end,
                        postorder_begin + i - inorder_begin, postorder_end - 1);

          break;
        }
      }
    }

    return cur;
  }

  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = inorder.size();
    TreeNode* root = traversal(inorder, postorder, 0, size, 0, size);
    return root;
  }
};
// @lc code=end
