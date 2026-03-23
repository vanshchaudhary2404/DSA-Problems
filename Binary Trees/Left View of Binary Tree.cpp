/* Author : Vansh Kumar
  Date : 2025-23-03
  Description: GFG problem-Left View of Binary Tree
*/
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> res;
        viewLeft( root , 0 , res);
        return res;
    }
    
    void viewLeft(Node* root , int level , vector<int>& res){
        if( root == NULL) return;
        
        if(res.size() == level) res.push_back(root->data);
        
        viewLeft( root->left , level+1 , res);
        viewLeft(root->right , level+1 , res);
    }
};
