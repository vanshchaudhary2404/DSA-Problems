/* Author : Vansh Kumar
  Date : 2025-10-29
  Description: Leetcode problem-136. Single Number.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int val : nums){
            ans ^= val;
        }

        return ans;
    }
};
