/* Author : Vansh Kumar
  Date : 2025-03-04
  Description: Leetcode problem-99. Recover Binary Search Tree
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

    //Approach 1 Recursive Approach : T.C = O(n) , S.C = O(n)

    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* sec = NULL;
    //INorder for finding swap pairs
    void inorder(TreeNode* root){
        if( root == NULL) return;

        inorder( root->left);

        if( prev!=NULL && root->val < prev->val ){
            if(!first){
                first = prev;
            }
            sec = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        //For Swapping the value got in first and sec;
        inorder(root);
        int temp = first->val;
        first->val = sec->val;
        sec->val = temp;
    }


    //Space Optimised code using morris traversal S.C =O(1) , T.C = O(n).



};
