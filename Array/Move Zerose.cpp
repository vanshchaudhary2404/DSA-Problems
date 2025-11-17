/* Author : Vansh Kumar
  Date : 2025-10-31
  Description: leetcode-283.   Move Zeroes.
*/
//Two Pointer approach. T.C = O(n) , S.C = O(1).
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      //Approach 1
        int left = 0;

        for(int right =0; right<nums.size(); right++){
            if(nums[right] != 0){
                swap( nums[left] , nums[right]);
                left++;
            }
        }


      //Approach 2
       int n = nums.size();
        int j;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }

        for(int i = j+1; i<n; i++){
            if(nums[i] != 0){
                swap( nums[i] , nums[j]);
                j++;
            }
        }
    }
};
