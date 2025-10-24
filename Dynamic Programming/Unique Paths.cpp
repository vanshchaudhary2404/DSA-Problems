/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: Leetcode problem -62 Unique Paths.
  There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
  Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
  The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/
class Solution {
public:

/*T.C -> O(2^(m+n)) , S.C -> O(m+n).
    int countPaths(int i, int j , int m , int n ){
        //Base case for false -> boundary case
        if( i >= m || j >= n){
            return 0;
        }
        //Base case for true.
        if( i == m-1 && j == n-1){
            return 1;
        }
        int down = paths(i+1 , j, m, n);
        int right = paths(i, j+1, m, n);

        return down + right;
    }
    int uniquePaths(int m, int n) {
        return countPaths( 0 , 0 ,m , n);
    }
*/
//Optimised approach using Memoization (Top-Down Dynamic Programming).
int countPaths(int i, int j, int m, int n, vector<vector<int>> &dp) {
        // Base Case: reached destination
        if (i == m - 1 && j == n - 1)
            return 1;

        // Out of bounds
        if (i >= m || j >= n)
            return 0;

        // If already computed, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // Compute both moves
        int right = countPaths(i, j + 1, m, n, dp);
        int down  = countPaths(i + 1, j, m, n, dp);

        // Store and return result
        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(0, 0, m, n, dp);
    }


};
