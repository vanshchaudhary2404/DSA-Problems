/* Author : Vansh Kumar
  Date : 2025-16-03
  Description: Leetcode problem-
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
    //Recursive approach
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root , res);
        return res;
    }

    void inorder(TreeNode* root , vector<int>& res ){
        if(root == NULL) return;
        inorder(root->left , res);
        res.push_back(root->val);
        inorder(root->right , res);
    }
    
    //Iterativr approach
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};
