/* Author : Vansh Kumar
  Date : 2025-22-03
  Description: Leetcode problem-124. Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root , maxi);
        return maxi;
    }
    int maxPath(TreeNode* root , int& maxi){
        if(!root) return 0;


        int left = max(0, maxPath(root->left , maxi));
        int right = max(0, maxPath(root->right , maxi));
        maxi = max(maxi , left+ root->val + right);

        return (root->val) + max(left , right);
    }
};
