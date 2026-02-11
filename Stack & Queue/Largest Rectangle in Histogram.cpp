/* Author : Vansh Kumar
  Date : 2025-12-02
  Description: Leetcode problem- 84 Largest Rectangle in Histogram
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       //approach 1.
       int n = heights.size();
       vector<int> left(n,0);//left smaller nearest
       vector<int> right(n,0);//right smaller nearest
       stack<int> s;

        //right smaller
        for(int i=n-1; i>=0; i--){//O(n)
            while( s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);        
        }
        while(!s.empty()){
            s.pop();
        }

        //left smaller
        for(int i=0; i<n; i++){//O(n)
            while( s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans =0;
        for(int i=0; i<n; i++){//O(n)
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans , currArea);
        }
        return ans;

       //Approach 2.
        /*heights.push_back(0); // sentinel
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;*/
    }
};
