/* Author : Vansh Kumar
  Date : 2025-23-03
  Description: GFG problem-Right View of Binary Tree
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
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> res;
        viewRightSide(root , 0 , res);
        return res;
    }
    
    void viewRightSide(Node* root , int level , vector<int>& res){
        if( root == NULL) return;
        
        if(res.size() == level) {
            res.push_back(root->data);
        }
        
        viewRightSide(root->right , level+1 , res );
        viewRightSide(root->left , level+1 , res);
    }
};
