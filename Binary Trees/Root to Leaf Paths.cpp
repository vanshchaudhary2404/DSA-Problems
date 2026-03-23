/* Author : Vansh Kumar
  Date : 2025-23-03
  Description: GFG problem-Root to Leaf Paths
*/
/*
Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<int> paths;
        vector<vector<int>> result;
        findPaths( root , paths , result);
        return result;
    }
    
    void findPaths(Node* root , vector<int>& paths , vector<vector<int>>& result){
        if(root == NULL) return;
        
        paths.push_back(root->data);
        
        if(root->left == NULL && root->right == NULL){
            result.push_back(paths);
        }else{
            findPaths(root->left , paths , result);
            findPaths(root->right , paths , result);
        }
        
        paths.pop_back();
    }
};
