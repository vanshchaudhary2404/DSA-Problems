/* Author : Vansh Kumar
  Date : 2025-30-03
  Description: Leetcode problem-114. Flatten Binary Tree to Linked List
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        //follow reverse logic right->left->root;
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};
