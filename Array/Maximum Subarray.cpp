/* Author : Vansh Kumar
  Date : 2025-10-16
  Description: leetcode- 53. Maximum Subarray
*/
class Solution {
public:
        //Brtue force T.C = O(n^3)
        /*int maxSum = INT_MIN; 
        int n = nums.size();
        for(int i =0; i<n; i++){
            for(int j=i; j<n; j++){
                int currSum =0; 
                for(int k=i; k<=j; k++){
                    currSum += nums[k];
                    maxSum = max( currSum , maxSum);
                }
            }
        }
        return maxSum;*/

        //Better Approach T.C =O(n^2)
        /*int maxSum = INT_MIN; 
        int n = nums.size();
        for(int st =0; st<n; st++){
            int currSum =0; 
            for(int end=st; end<n; end++){
                currSum += nums[end];
                maxSum = max( currSum , maxSum);
            }
        }
        return maxSum;*/

    //OPtinmal Approach : T.C = O(n) , S.C = O(1)
    int maxSubArray(vector<int>& nums) {
        int currSum =0 , maxSum = INT_MIN;
        for(int val : nums){
            currSum += val;
            maxSum = max(currSum , maxSum);
            if( currSum < 0) currSum = 0;
        }

        return maxSum;
    }
};
