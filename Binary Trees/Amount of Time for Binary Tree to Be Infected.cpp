/* Author : Vansh Kumar
  Date : 2025-27-03
  Description: Leetcode problem-2385. Amount of Time for Binary Tree to Be Infected
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
    //Step1
    TreeNode* markParent(TreeNode* root , unordered_map<TreeNode* , TreeNode*>& parent , int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = NULL;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start){
                target = node;
            }

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
        return target;
    }

    //step 2
    int burnTree(TreeNode* target , unordered_map<TreeNode* , TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode* , bool> visited;
        visited[target] = true;

        int time = 0;

        while(!q.empty()){
            int size = q.size();

            bool flag = false;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                //left side
                if(node->left && !visited[node->left]){
                    visited[node->left] = true;
                    q.push(node->left);
                    flag = true;
                }
                //right child
                if(node->right && !visited[node->right]){
                    visited[node->right] = true;
                    q.push(node->right);
                    flag = true;
                }
                //parent
                if(parent[node] && !visited[parent[node]]){
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                    flag = true;
                }
            }
            if(flag) time++;
        }
        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode* > mpp;
        TreeNode* target = markParent(root , mpp , start);
        int maxi = burnTree(target , mpp);
        return maxi;
    }
};
