/* Author : Vansh Kumar
  Date : 2025-12-04
  Description: Leetcode problem-152. Maximum Product Subarray
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Brute force T.C->(N^2), S.C->O(1)
        /*int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int prod =1;
            for(int j=i; j<n; j++){
                prod *= nums[j];
                maxi = max( maxi , prod);
            }
        }
        return maxi;*/

        //Optimal Approach T.C->(N), S.C->O(1)
        int prefix = 1, suffix = 1, maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if( prefix == 0) prefix =1;
            if(suffix == 0) suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix* nums[n-i-1];
            maxi = max( maxi , max(suffix , prefix));
        }
        return maxi;
    }
};
