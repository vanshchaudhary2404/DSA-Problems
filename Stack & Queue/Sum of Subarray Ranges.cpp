/* Author : Vansh Kumar
  Date : 2025-13-02
  Description: Leetcode problem-2104. Sum of Subarray Ranges
*/
class Solution {
public:
    vector<int> PSE(vector<int>&arr){
        int n = arr.size();
        stack<int> s;
        vector<int> pse(n);
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }
    vector<int> NSE(vector<int>&arr){
        int n = arr.size();
        stack<int> s;
        vector<int> nse(n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            nse[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nse;
    }
     long long sumMin(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse = PSE(nums);
        vector<int> nse = NSE(nums);

        long long total = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total += (long long)nums[i] * left * right;
        }
        return total;
    }
//--------------------------------------------------------------------------------
    vector<int> NGE(vector<int>&arr){
        int n = arr.size();
        stack<int> s;
        vector<int> nge(n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && arr[s.top()] <= arr[i]){
                s.pop();
            }
            nge[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return nge;
    }
    vector<int> PGE(vector<int>&arr){
        int n = arr.size();
        stack<int> s;
        vector<int> pge(n);
        for(int i=0; i<n; i++){
            while(!s.empty() && arr[s.top()] < arr[i]){
                s.pop();
            }
            pge[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pge;
    }
     long long sumMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge = PGE(nums);
        vector<int> nge = NGE(nums);

        long long total = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total += (long long)nums[i] * left * right;
        }
        return total;
    }
//---------------------------------------------------------------------------
    long long subArrayRanges(vector<int>& nums) {
        return sumMax(nums) - sumMin(nums);
    }
};
