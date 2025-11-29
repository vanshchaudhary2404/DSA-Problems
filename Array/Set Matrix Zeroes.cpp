/* Author : Vansh Kumar
  Date : 2025-11-30
  Description: Leetcode problem-73. Set Matrix Zeroes
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //Better approach m*n -> m->rows & n->col
       /*int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);
        //First pass: mark rows and cols that need to be zeroed
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        // Second pass: set cells to zero if their row or col is marked
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }*/

        //OPTIMAL Approach S.C->O(1)
        int n = matrix.size();         // rows
        int m = matrix[0].size();      // cols

        int col0 = 1;  // flag to check if FIRST COLUMN needs to be zero
        // STEP 1: Mark rows & columns using first row and first column
        for(int i = 0; i < n; i++) {
            // If any element in first column is 0 → whole column must be zero
            if(matrix[i][0] == 0) 
                col0 = 0;
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    // mark row i → put marker at first column
                    matrix[i][0] = 0;
                    // mark column j → put marker at first row
                    matrix[0][j] = 0;
                }
            }
        }
        // STEP 2: Use markers to set the cells to zero
        // (skip 1st row and 1st col for now)
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                // If row i or col j was marked → set matrix[i][j] = 0
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // STEP 3: Handle FIRST ROW separately
        // If matrix[0][0] is 0 → the entire first row must be zero
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
        // STEP 4: Handle FIRST COLUMN separately
        // If col0 == 0 → entire first column must be zero
        if(col0 == 0) {
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};
