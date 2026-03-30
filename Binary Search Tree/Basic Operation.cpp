#include<iostream>
#include<vector>
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

Node* insertIntoBST(Node* root , int val){
  if(root == NULL) return new Node(val);

  if( val < root->data){
    root->left = insertIntoBST(root->left , val);
  }else{
    root->right = insertIntoBST(root->right , val);
  }

}

Node* buildBST(vector<int> arr){
  Node* root = NULL;
  for(int val : arr){
    root = insertIntoBST(root , val);
  }

  return root;
}

void inorder(Node* root){
  if(!root) return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);

}

bool searchBST(Node* root , int key){

  if(root == NULL) return false;
  if( root->data == key) return true;

  if( key < root->data){
    return searchBST(root->left , key);
  }else{
    return searchBST(root->right , key);
  }

}

Node* getInorderSuccessor( Node* root){
  while( root != NULL && root->left != NULL){
    return root->left;
  }
  return root;
}

Node* delNode(Node* root , int key){
  if( root == NULL) return NULL;

  if(key < root->data){
    root->left = delNode(root->left , key);
  }else if(key > root->data){
    root->right = delNode(root->right , key);
  }else{
    //Key == root
    //For no cild & one child
    if(root->left == NULL){
      Node* temp = root->right;
      delete root;
      return temp;
    }else if(root->right == NULL){
      Node* temp = root->left;
      delete root;
      return temp;
    }else{// 2 child
      Node* IS = getInorderSuccessor(root->right);
      root->data = IS->data;
      root->right = delNode(root->right , IS->data);
    }
  }
  return root;
}


int main(){
  vector<int> arr = {3,2,1,5,6,4};

  Node* root = buildBST(arr);
  //Verify
  cout<< "Before : ";
  inorder(root);
  cout<<endl;

 
  //Search
  cout<< "searching : " <<searchBST(root , 4)<<endl;

  //DELETION

  //1. no child
  /*delNode(root , 1);
  cout<< "After : ";
  inorder(root);
  cout<<endl;*/

  //2. one child
  /*delNode(root , 6);
  cout<< "After : ";
  inorder(root);
  cout<<endl;*/

  //3. two child
  delNode(root , 5);
  cout<< "After : ";
  inorder(root);
  cout<<endl;
  
  return 0;
}
