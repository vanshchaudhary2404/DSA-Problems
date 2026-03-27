/* Author : Vansh Kumar
  Date : 2025-28-03
  Description: Leetcode problem-106. Construct Binary Tree from Inorder and Postorder Traversal
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
    //T.c = O(N) & S.C = O(N)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // Map to store value -> index (for O(1) lookup)
        unordered_map<int, int> map;
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }

        // Start recursion
        return helper(inorder, 0, inorder.size()-1,
                      postorder, 0, postorder.size()-1, map);
    }

    TreeNode* helper(vector<int>& inorder, int is, int ie,
                     vector<int>& postorder, int ps, int pe,
                     unordered_map<int, int>& map) {

        // Base case: no elements
        if(ps > pe || is > ie) return NULL;

        //SELF NOTE:
        // Postorder last element = ROOT
        TreeNode* root = new TreeNode(postorder[pe]);

        // Find root in inorder
        int inRoot = map[postorder[pe]];

        // Number of nodes in left subtree
        int numLeft = inRoot - is;

        //SELF NOTE:
        // Inorder splits tree
        // Left  = is → inRoot-1
        // Right = inRoot+1 → ie

        // Build LEFT subtree
        root->left = helper(inorder, is, inRoot-1,
                            postorder, ps, ps + numLeft - 1, map);

        // Build RIGHT subtree
        root->right = helper(inorder, inRoot + 1, ie,
                             postorder, ps + numLeft, pe - 1, map);

        return root;
    }
};
