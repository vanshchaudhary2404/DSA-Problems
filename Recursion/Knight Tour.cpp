/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: LeetCpde Problem-2596. Check Knight Tour Configuration
  There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.
  You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] indicates that the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.
  Return true if grid represents a valid configuration of the knight's movements or false otherwise.
  Note that a valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally and one square vertically. The figure below illustrates all the possible eight moves of a knight from some cell.
*/
class Solution {
public:
    bool isValid( vector<vector<int>>&grid , int r , int c ,int n , int expVal){
        //Base Case
        if( r>= n || c>=n || r<0 || c<0 || grid[r][c] != expVal){
            return false;
        }
        if( expVal == n*n-1){
            return true;
        }

        int ans1 = isValid(grid , r-2 , c+1 , n , expVal+1);
        int ans2 = isValid(grid , r-1 , c+2 , n , expVal+1);
        int ans3 = isValid(grid , r+1 , c+2 , n , expVal+1);
        int ans4 = isValid(grid , r+2 , c+1 , n , expVal+1);
        int ans5 = isValid(grid , r+2 , c-1 , n , expVal+1);
        int ans6 = isValid(grid , r+1 , c-2 , n , expVal+1);
        int ans7 = isValid(grid , r-1 , c-2 , n , expVal+1);
        int ans8 = isValid(grid , r-2 , c-1 , n , expVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid , 0, 0, grid.size() , 0); 
    }
};
