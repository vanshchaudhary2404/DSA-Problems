/* Author : Vansh Kumar
  Date : 2025-27-03
  Description: Leetcode problem-105. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = helper(preorder , 0 , preorder.size()-1 , inorder , 0 , inorder.size()-1 , inMap);
        //(preorder , preStart , preEnd , inorder , inStart , inEnd , inMap)
        return root;
    }

    TreeNode* helper(vector<int>& preorder , int preStart , int preEnd , 
                    vector<int>& inorder , int inStart , int inEnd , unordered_map<int , int>& inMap){
        
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = helper(preorder , preStart+1 ,  preStart + numsLeft , 
                            inorder , inStart ,  inRoot-1 , inMap); 

        root->right = helper(preorder ,  preStart + numsLeft +1 , preEnd , 
                            inorder ,  inRoot+1 , inEnd , inMap);

        return root;
    }
}class Solution {
public:
    //add comment for shelf note , T.C = O(N) & S.C = O(N).
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store value -> index in inorder for O(1) lookup
        map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        // Start recursive construction
        TreeNode* root = helper(preorder, 0, preorder.size()-1,
                                inorder, 0, inorder.size()-1, inMap);
        return root;
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, 
                     vector<int>& inorder, int inStart, int inEnd, map<int, int> inMap){
        
        // Base case: no elements to construct subtree
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }

        // First element of preorder is always root
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find root index in inorder to split left & right subtree
        int inRoot = inMap[root->val];

        // Number of nodes in left subtree
        int numsLeft = inRoot - inStart;

        // Build left subtree using next numsLeft elements in preorder
        root->left = helper(preorder, preStart + 1, preStart + numsLeft,
                            inorder, inStart, inRoot - 1, inMap); 

        // Build right subtree using remaining elements
        root->right = helper(preorder, preStart + numsLeft + 1, preEnd,
                             inorder, inRoot + 1, inEnd, inMap);

        return root;
    }
};
