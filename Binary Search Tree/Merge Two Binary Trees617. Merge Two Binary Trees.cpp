/* Author : Vansh Kumar
  Date : 2025-08-04
  Description: Leetcode problem-617. Merge Two Binary Trees
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;

        // Merge current node
        root1->val += root2->val;

        // Merge left and right subtree
        root1->left = mergeTrees(root1->left , root2->left);
        root1->right = mergeTrees(root1->right , root2->right);


        return root1;
    }
};
