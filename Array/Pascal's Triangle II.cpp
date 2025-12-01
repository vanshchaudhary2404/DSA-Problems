  /* Author : Vansh Kumar
  Date : 2025-12-01
  Description: Leetcode problem-119. Pascal's Triangle II
*/
  class Solution {
public:
    vector<int> getRow(int rowIndex) {
       
        /*Brute force ( not good because we generate all rows intit and return the required one)
        vector<vector<int>> result(rowIndex+1);

        //array size in each row
        for(int i=0; i<rowIndex+1; i++){
           result[i] = vector<int>(i+1,1); //next row with 1st element 1
           
           //next row element from 1st index because 1st is 1 always
           for(int j=1; j<i; j++){
                result[i][j] = result[i-1][j] + result[i-1][j-1]; //upper element & right diagonal eleemnt.
           }
        }
        return result[rowIndex];*/

        //Optimal approach
        vector<int> prev;

        //array size in each row
        for(int i=0; i<rowIndex+1; i++){
            vector<int> curr(i+1,1); //next row with 1st element 1
           
           //next row element from 1st index because 1st is 1 always
           for(int j=1; j<i; j++){
                curr[j] = prev[j] + prev[j-1]; //upper element & right diagonal eleemnt.
           }
           prev = curr;
        }
        return prev;
         
    }
};
