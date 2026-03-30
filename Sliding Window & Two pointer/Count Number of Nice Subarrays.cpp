/* Author : Vansh Kumar
  Date : 2025-30-03
  Description: Leetcode problem-1248. Count Number of Nice Subarrays
*/
class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int l = 0, r = 0, oddCnt = 0 , cnt = 0;
        if(k <0 ) return 0;
        while( r < nums.size()){
            if(nums[r]%2 !=0){
                oddCnt++;
            }

            while( oddCnt > k){
                if(nums[l]%2 !=0){
                    oddCnt--;
                }
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums , k) - atMost(nums , k-1);
    }
};
