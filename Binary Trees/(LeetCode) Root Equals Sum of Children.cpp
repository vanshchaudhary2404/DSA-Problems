/* Author : Vansh Kumar
  Date : 2025-25-03
  Description: Leetcode problem-2236. Root Equals Sum of Children
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
    bool checkTree(TreeNode* root) {
        
        //Brute Force
        // if(!root) return true;

        // int child = 0;
        // if(root->left ) child += root->left->val;
        // if(root->right) child += root->right->val;

        // if(child == root->val) return true;
        // else return false;


        //Optimized.
        if(!root) return true;
        
        if (root->left == NULL && root->right == NULL)
             return true;
        int left = 0, right = 0;

        if (root->left != NULL)
            left = root->left->val;

         if (root->right != NULL)
            right = root->right->val;

        // Check current node + recursive check
        return (root->val == left + right) &&
                checkTree(root->left) &&
                checkTree(root->right);
    }
};
