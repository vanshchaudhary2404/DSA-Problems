/* Author : Vansh Kumar
  Date : 2025-23-03
  Description: Leetcode problem-987. Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>> nodes;//col , row , multiset
        queue<pair<TreeNode* , pair<int ,int>>> todo;

        todo.push({root , {0 , 0}});//(root , (col , row)); 
        while(!todo.empty()){
            auto q = todo.front();
            todo.pop();

            TreeNode* node = q.first;
            int col = q.second.first , row = q.second.second;
            nodes[col][row].insert(node->val);
            if(node->left){
                todo.push({node->left , {col-1 , row+1}});
            }
            if(node->right){
                todo.push({node->right , {col+1 , row+1}});
            }
        }
        vector<vector<int>> res;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
