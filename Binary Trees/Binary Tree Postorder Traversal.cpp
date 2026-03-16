/* Author : Vansh Kumar
  Date : 2025-16-03
  Description: Leetcode problem-145. Binary Tree Postorder Traversal
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
    //recursive approach
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root , res);
        return res;
    }
    void postorder(TreeNode* root , vector<int>& res){
        if( root == NULL) return;
        postorder(root->left , res);
        postorder(root->right , res);
        res.push_back(root->val);
    }

    //Iterative method using 2 stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> st;
        TreeNode* last = NULL;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root -> left;
            } else {
                TreeNode* node = st.top();
                if (node -> right && last != node -> right) {
                    root = node -> right;
                } else {
                    nodes.push_back(node -> val);
                    last = node;
                    st.pop();
                }
            }
        }
        return nodes;
    }
};
