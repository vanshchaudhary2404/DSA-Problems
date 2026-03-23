/* Author : Vansh Kumar
  Date : 2025-23-03
  Description: Leetcode problem-257. Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root , "" , ans);
        return ans;   
    }

    void helper(TreeNode* root , string path , vector<string>& ans){
        if(root == NULL ) return;
        //append curr node vlaue 
        if(path == ""){
            path = to_string(root->val);
        }else{
            path += "->" + to_string(root->val);
        }

        //If Leaf Node
        if(!root->left && !root->right){
            ans.push_back(path);
            return;
        }else{
            helper(root->left , path , ans);
            helper(root->right , path , ans);
        }
    }
};
