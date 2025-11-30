/* Author : Vansh Kumar
  Date : 2025-11-30
  Description: Leetcode problem-118. Pascal's triangle
*/
class Solution {
public:
    vector<int> generateRows(int row){
        // generate a single row using nCr logic
        long long ans =1;
        vector<int> ansRow;
        //first element of triangle is always 1
        ansRow.push_back(1);

        /*Build remaining elements using nCr relation:
         C(r, c) = C(r, c-1) * (r - c) / c
        Avoids factorials → prevents overflow + faster*/
        for(int col =1; col<row; col++){
            ans = ans*(row-col); // numerator shrinks each step
            ans = ans / col;    //divide by current column index
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    
    // Each row i corresponds to 1-indexed n = i → row values = C(i-1, c)
    vector<vector<int>> generate(int numRows) {// USING Ncr method -> element position.
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back( generateRows(i));// build each row independently
        }
        return ans;
    }
};
