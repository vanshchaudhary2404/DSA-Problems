/* Author : Vansh Kumar
  Date : 2025-10-07
  Description:  N-QueensII
  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
  Given an integer n, return the number of distinct solutions to the n-queens puzzle.
*/
class Solution {
public:
    bool isSafe(vector<string> &board , int row , int col,  int n ){
        //vertical -- upper col
        for(int i =0; i<row; i++){
            if(board[i][col]== 'Q')
                return false;
        }
        //left diagonal
        for(int i=row , j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j]=='Q')
                return false;
        }
        //right diagonal
        for(int i=row , j=col; i>=0 && j<n; i--,j++){
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }

    int nQueens(vector<string> &board , int row , int n ){
        if( row == n){
            return 1;
        }
        int count =0;
        for(int j=0; j<n; j++){
            if(isSafe(board ,row ,  j , n)){
                board[row][j] = 'Q';
                count += nQueens(board , row+1 , n );
                board[row][j] = '.';
            }
        }
        return count;
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        return nQueens( board , 0 , n);
    }
};
