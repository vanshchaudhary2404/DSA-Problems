/* Author : Vansh Kumar
  Date : 2025-08-04
  Description: Leetcode problem-Inorder Predecessor & Successor for particular key.
*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// basic BST node
struct Node{
  int data;
  Node* left;
  Node* right;

  Node( int val){
    data = val;
    left = right = NULL;
  }
};


// helper: largest value in left subtree (inorder predecessor inside subtree)
Node* rightMostInLeftSubtree(Node* root){
  Node* ans = NULL;
  while( root!= NULL){
    ans = root;
    root = root->right;
  }

  return ans;
}

// helper: smallest value in right subtree (inorder successor inside subtree)
Node* leftMostInRightSubtree(Node* root){
  Node* ans = NULL;
  while( root!= NULL){
    ans = root;
    root = root->left;
  }

  return ans;
}


// returns {predecessor, successor} for given key in BST
vector<int> getPredSucc(Node* root , int key){
  Node* curr = root;
  Node* pred = NULL;
  Node* succ = NULL;

  // walk down the tree keeping track of closest smaller (pred)
  // and closest greater (succ) nodes
  while(curr != NULL ){
    if( key < curr->data){//curr node is potential inorder  successor
      succ = curr;
      curr = curr->left;
    }else if(key > curr->data){ // curr node is potential inorder predecessor
      pred = curr;
      curr = curr->right;
    }else{
      if(curr->left != NULL){
        //INorder predecessor
        pred = rightMostInLeftSubtree(curr->left);
      }
      if(curr->right != NULL){
        //Inorder successor;
        succ = leftMostInRightSubtree(curr->right);
      }
      break;
    }
  }
  return {pred->data , succ->data};

}

int main(){
  // create sample BST
  Node* root = new Node(6);
  root->left = new Node(4);
  root->right = new Node(8);
  root->left->left = new Node(1);
  root->left->right = new Node(5);
  root->right->left = new Node(7);
  root->right->right = new Node(9);

  int key = 7; // find pred & succ of this key
  vector<int> ans = getPredSucc(root , key);
  cout<<"predecessor: "<< ans[0] << endl;
  cout<<"successor: "<< ans[1] << endl; 

  return 0;
}
