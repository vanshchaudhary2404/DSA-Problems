/* Author : Vansh Kumar
  Date : 2025-01-04
  Description: Leetcode problem-230. Kth Smallest Element in a BST
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
    int prevOrder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;
        
        //INorder 
        //Left
        if(root->left != NULL){
            int leftAns = kthSmallest(root->left , k);
            if( leftAns != -1){
                return leftAns;
            }
        }

        //Root
        if(prevOrder+1 == k){
            return root->val;
        }
        prevOrder= prevOrder+1;

        //Right
        if(root->right != NULL){
            int rightAns = kthSmallest(root->right , k);
            if( rightAns != -1){
                return rightAns;
            }
        }
        return -1;
    }
};
