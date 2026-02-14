/* Author : Vansh Kumar
  Date : 2025-14-02
  Description: Leetcode problem-85. Maximal Rectangle
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int h = heights[st.top()];//store increasing height.
                st.pop();
                int width = st.empty() ? i : i- st.top() -1;
                maxArea = max(maxArea , h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();//row
        int m = matrix[0].size();//col

        vector<vector<int>> prefixSum(n , vector<int>(m,0));//column sum.

        //step1 build row-wise prefix
        for(int i=0; i<n; i++){
            int sum =0;
            for(int j=0; j<m; j++){
                if( matrix[i][j] == '1')
                    sum += 1;
                else 
                    sum = 0;
                
                prefixSum[i][j] = sum;
            }
        }

        int maxArea = 0;

        //step2 treat each col as histogram
        for(int j=0; j<m; j++){
            vector<int> height(n);

            for(int i=0; i<n; i++){
                height[i] = prefixSum[i][j];
            }

            maxArea = max(maxArea , largestRectangleArea(height));
        }
        return maxArea;
    }
};
