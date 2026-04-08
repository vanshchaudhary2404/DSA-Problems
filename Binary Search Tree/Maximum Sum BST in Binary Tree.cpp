/* Author : Vansh Kumar
  Date : 2025-08-04
  Description: Leetcode problem-1373. Maximum Sum BST in Binary Tree
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
    int maxSum = 0;
    struct NodeInfo{
        bool isBST;
        int minVal , maxVal , sum;
    };

    NodeInfo dfs(TreeNode* root){
        if(!root){
            return {true , INT_MAX , INT_MIN , 0}; 
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if(left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal){

                int currSum = left.sum + right.sum + root->val;
                maxSum = max(maxSum , currSum);

                return {true , min(root->val , left.minVal) , max(root->val , right.maxVal) , currSum};
            }

            return {false , 0 , 0 , 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
