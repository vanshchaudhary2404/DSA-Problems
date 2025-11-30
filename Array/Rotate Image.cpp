/* Author : Vansh Kumar
  Date : 2025-11-30
  Description: Leetcode problem-48. Rotate Image
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Brute force O(n^2)
        /*int n = matrix.size();
        vector<vector<int>> temp(n , vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp[j][(n-1)-i] = matrix[i][j];
            }
        } 
        // Copy back into original matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = temp[i][j];
            }
        }*/


        //OPtimal Approach space O(1)
        /*Step1 : transpose the matrix 
        step 2: reverse each row to get the desired result*/
        int n = matrix.size();
        //Step 1: Transpose.
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        // Step 2 : Reverse each  row
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};
