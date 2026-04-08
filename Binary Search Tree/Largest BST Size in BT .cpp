/* Author : Vansh Kumar
  Date : 2025-08-04
  Description: Largest BST Size in BT 
*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;

  Node( int val){
    data = val;
    left = right = NULL;
  }
};



//Find size of largest BST
class Info{
  public:
    int min , max , size;

    Info(int mi , int mx , int sz){
        min = mi;
        max = mx;
        size = sz;
    }
};


Info helper(Node* root){
  if( root == NULL){
    return Info(INT_MAX , INT_MIN , 0);
  }

  Info left = helper(root->left);
  Info right = helper(root->right);

  if(root->data > left.max && root->data < right.min){
    int currMin = min(root->data , left.min);
    int currMax = max(root->data , right.max);
    int currSz = left.size + right.size + 1;

    return Info(currMin , currMax , currSz);
  }

  return Info(INT_MIN , INT_MAX , max(left.size , right.size));

}

int largestBSTinBT(Node* root){
  Info info = helper(root);
  return info.size;
}


int main(){

  Node* root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(15);
  root->left->left = new Node(1);
  root->left->right = new Node(8);
  root->right->right = new Node(7); 

  cout<< largestBSTinBT(root) <<endl;

  return 0;
}
