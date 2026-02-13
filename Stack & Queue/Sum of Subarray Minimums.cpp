/* Author : Vansh Kumar
  Date : 2025-13-02
  Description: Leetcode problem-907. Sum of Subarray Minimums
*/
class Solution {
public:
    vector<int> prevSmallerEle(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while( !st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i); 
        }
        return pse;
    }
    vector<int> nextSmallerEle(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            while( !st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i); 
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        //Approach 1: Brute force 
        //T.C-> O(n2) , S.C->O(1)
        /*
        int n = arr.size();
        long long sum = 0;
        int mod = 1e9 + 7;

        for(int i=0; i<n; i++){
            int mini = arr[i];
            for(int j=i; j<n; j++){
                mini = min(mini , arr[j]);
                sum = (sum + mini) % mod;
            }
        }
        return sum;
        */

        //Approach 2: stack based
        int n = arr.size();
        long long ans = 0;

        vector<int> pse = prevSmallerEle(arr);
        vector<int> nse = nextSmallerEle(arr);
        int mod = 1e9+7;

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + (right * left * 1LL * arr[i])) % mod;
        }

        return ans;
    }
};
