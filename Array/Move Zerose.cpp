/* Author : Vansh Kumar
  Date : 2025-10-31
  Description: leetcode-283.   Move Zeroes.
*/
//Two Pointer approach.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for(int right =0; right<nums.size(); right++){
            if(nums[right] != 0){
                swap( nums[left] , nums[right]);
                left++;
            }
        }
    }
};
