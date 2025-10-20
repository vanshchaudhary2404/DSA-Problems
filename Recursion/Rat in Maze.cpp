/* Author : Vansh Kumar
  Date : 2025-10-20
  Description: GFG. Rat In maze
*/

//this code has T.C-> o(4^(n^2)) , S.C->O(n^2).
#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int>> &mat ,  int r , int c , string path , vector<string> &ans ,
            vector<vector<bool>> &vis ){
  int n = mat.size();
  //Base case
  if( r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c] == true ){
    return;
  }
  //Answer
  if( r == n-1 && c == n-1 ){
    ans.push_back(path);
    return;
  }
  vis[r][c] = true;
  //Recursive calls
  helper(mat, r+1, c , path+"D", ans , vis );//down 
  helper(mat, r-1, c , path+"U", ans , vis );//up
  helper(mat, r, c-1 , path+"L", ans , vis );//left
  helper(mat, r, c+1 , path+"R", ans , vis );//right

  vis[r][c] = false;
}

vector<string> findPath(vector<vector<int>> &mat){
  int n = mat.size();
  vector<string> ans;
  string path = "";
  vector<vector<bool>> vis(n, vector<bool>(n, false));
  helper( mat , 0 , 0 , path , ans, vis);//matrix , row , col , path(UP , Down , Left , Right) , ans;
  return ans;
}

int main(){
  vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
  vector<string> ans = findPath(mat);
  for(string path : ans){
    cout<< path << endl;
  }
  return 0;
}


// Optimized code of space complexity having T.C-> o(4^(n^2)) , S.C->O(1).
void helper(vector<vector<int>> &mat ,  int r , int c , string path , vector<string> &ans){
  int n = mat.size();
  //Base case
  if( r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1 ){
    return;
  }
  //Answer
  if( r == n-1 && c == n-1 ){
    ans.push_back(path);
    return;
  }

  mat[r][c] = -1;
  //Recursive calls
  helper(mat, r+1, c , path+"D", ans );//down 
  helper(mat, r-1, c , path+"U", ans );//up
  helper(mat, r, c-1 , path+"L", ans );//left
  helper(mat, r, c+1 , path+"R", ans );//right

  mat[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &mat){
  int n = mat.size();
  vector<string> ans;
  string path = "";

  helper( mat , 0 , 0 , path , ans);//matrix , row , col , path(UP , Down , Left , Right) , ans;
  return ans;
}

int main(){
  vector<vector<int>> mat = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

  vector<string> ans = findPath(mat);
  for(string path : ans){
    cout<< path << endl;
  }

  return 0;
}

