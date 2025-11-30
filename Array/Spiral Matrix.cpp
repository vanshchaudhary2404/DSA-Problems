/* Author : Vansh Kumar
  Date : 2025-11-30
  Description: Leetcode problem-54. Spiral Matrix.
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //Four sides TOP , RIGHT , BOTTOM , LEFT.
        int m = matrix.size(); //row
        int n = matrix[0].size();//col
        int sRow = 0 , eRow = m-1, sCol = 0 , eCol = n-1;
        vector<int> ans;
        while(  sRow <= eRow && sCol <= eCol ){
            //Top
            for(int j=sCol; j<=eCol; j++){
                ans.push_back( matrix[sRow][j]);
            }
            //RIGHT
            for(int i=sRow+1; i<=eRow; i++){
                ans.push_back( matrix[i][eCol]);
            }
            //BOTTOM
            for(int j=eCol-1; j>=sCol; j--){
                if(sRow == eRow){
                    break;
                }
                ans.push_back( matrix[eRow][j]);
            }
            //LEFT
            for(int i=eRow-1; i>=sRow+1; i--){
                if(sCol == eCol){
                    break;
                }
                 ans.push_back( matrix[i][sCol]);
            }
            sRow++; eRow--; sCol++; eCol--;
        }
        return ans;
    }
};
