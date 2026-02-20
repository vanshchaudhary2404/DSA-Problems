/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-1004. Max Consecutive Ones III
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //Brutr force generate all subarray and count zeros ,
        // if count of zero's > k break; else calculate maxLen.
        /*
        int n = nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int zeros = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == 0) zeros++;
                if( zeros <= k){
                    int len = j-i+1;
                    maxLen = max(maxLen , len);
                }else{
                    break;
                }
            }
        }
        return maxLen;
        */

        //Approach 2 : optimize :-> using 2 pointer & sliding window.
        int n = nums.size();
        int l = 0 , r = 0, maxLen = 0 , zeros = 0;;
        while( r < n){
            if( nums[r] == 0){
                zeros++;
            }
            // Shrink window until valid
            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            // Update answer
            int len = r-l+1;
            maxLen = max(maxLen , len);
            r++;
        } 
        return maxLen;
    }
};
