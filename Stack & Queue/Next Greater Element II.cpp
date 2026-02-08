/* Author : Vansh Kumar
  Date : 2025-08-02
  Description: Leetcode problem-503
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n ,-1);
        stack<int> st;
    
        //traverse from 2n-1 to 0 to simulate circular array
        for(int i=2*n-1; i>=0; i--){//O(2N)
            //remove ele. smaller or equal to current
            while( st.size() > 0 && st.top() <= nums[i%n]){
                st.pop();//O(N)
            }
            
            //fill answer only for original indices
            if(i<n){
                nge[i] = st.empty() ? -1 : st.top();
            }

            //push curr element for future comparisons
            st.push(nums[i%n]);//O(2N)
        }
        return nge;
    }
};
