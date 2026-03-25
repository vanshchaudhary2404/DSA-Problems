/* Author : Vansh Kumar
  Date : 2025-25-03
  Description: Leetcode problem-222. Count Complete Tree Nodes
*/
/*
🔹 Key Optimization Idea

Instead of counting every node (O(N)), we use height properties:

Perfect Binary Tree nodes =
👉 
2
ℎ
−
1
2
h
−1
We check if a subtree is perfect using:
Left height (lh) → go fully left
Right height (rh) → go fully right
🔹 Core Logic
1. Base Case
If node is NULL → return 0
2. Find Heights
Compute:
lh = left height
rh = right height
3. Compare Heights
✅ Case 1: lh == rh
Tree is perfect

Direct formula:

nodes = (1 << lh) - 1

(same as 2^h−1)

❌ Case 2: lh != rh
Tree is not perfect
Recursively count:
nodes = 1 + left subtree + right subtree

🔹 Height Calculation
Start from node
Move:
Left for lh
Right for rh
Count steps until NULL
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = findHeightL(root);
        int rh =  findHeightR(root);

        if(lh == rh) return (1<<lh) -1;

        return 1+ countNodes(root->left) + countNodes(root->right);
    }

    int findHeightL(TreeNode* node){
        int heightCount =0;
        while(node){
            heightCount++;
            node = node->left;
        }
        return heightCount;
    }
    int findHeightR(TreeNode* node){
        int heightCount =0;
        while(node){
            heightCount++;
            node = node->right;
        }
        return heightCount;
    }
};
