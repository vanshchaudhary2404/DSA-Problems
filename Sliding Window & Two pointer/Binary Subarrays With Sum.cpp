/* Author : Vansh Kumar
  Date : 2025-30-03
  Description: Leetcode problem-930. Binary Subarrays With Sum
*/
class Solution {
public:
    int atMost(vector<int>& nums ,int goals){
        if(goals < 0) return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        while( r < nums.size()){
            sum += nums[r];
            while( sum > goals){
                sum = sum - nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums ,goal) - atMost(nums , goal-1);
    }
};
