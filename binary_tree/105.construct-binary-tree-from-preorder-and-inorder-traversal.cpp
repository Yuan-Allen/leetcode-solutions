/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *traversal(vector<int> &preorder, vector<int> &inorder,
                        int &preIdx, int inorderLeft, int inorderRight,
                        unordered_map<int, int> &inorderMap) {
        if (inorderLeft >= inorderRight) {
            return nullptr;
        }

        TreeNode *cur = new TreeNode(preorder[preIdx]);
        // int inorderIndex =
        //     find(inorder.begin(), inorder.end(), preorder[preIdx]) -
        //     inorder.begin();
        // Opt: unordered_map
        int inorderIndex = inorderMap[preorder[preIdx]];
        ++preIdx;
        cur->left = traversal(preorder, inorder, preIdx, inorderLeft,
                              inorderIndex, inorderMap);
        cur->right = traversal(preorder, inorder, preIdx, inorderIndex + 1,
                               inorderRight, inorderMap);
        return cur;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> inorderMap;
        int preIdx = 0;
        int idx = 0;
        for (int &val : inorder) {
            inorderMap[val] = idx++;
        }
        return traversal(preorder, inorder, preIdx, 0, inorder.size(),
                         inorderMap);
    }
};
// @lc code=end
