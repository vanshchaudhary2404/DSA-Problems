/* Author : Vansh Kumar
  Date : 2025-16-03
  Description: Leetcode problem-144. Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root , res);
        return res;
    }

    void preorder(TreeNode* root , vector<int>& res){
        if(root == NULL) return;
        res.push_back(root->val);
        preorder(root->left , res);
        preorder(root->right , res);
    }


    //Iterativr approach
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>st;
        while (root || !st.empty()) {
            if (root) {
                ans.push_back(root -> val);
                if (root -> right) {
                    st.push(root -> right);
                }
                root = root -> left;
            } else {
                root = st.top();
                st.pop();
            }
        }
        return ans;
    }
};
