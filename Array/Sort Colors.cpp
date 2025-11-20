/* Author : Vansh Kumar
  Date : 2025-10-28
  Description: Leetcode problem-75. Sort colors
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Brute Force : T.c = O(nlogn)
        //sort( nums.begin() , nums.end());
        
        //Optimized Approach : T.C= O(n) In 2 Passes.
        /*int n = nums.size();
        int count0 =0, count1 = 0, count2 = 0;

        for(int i=0; i<n; i++ ){
            if(nums[i] == 0) count0++;
            else if ( nums[i] == 1) count1++;
            else count2++;
        }
        int idx = 0;
        for(int i =0; i<count0; i++){
            nums[idx++] =0;
        }
        for(int i =0; i<count1; i++){
            nums[idx++] = 1;
        }
        for(int i =0; i<count2; i++){
            nums[idx++] = 2;
        }*/

        //Optimal Approach Using Dutch National Flag Algo :  T.C=O(n) In One pass.
        int n = nums.size();
        int mid =0, low =0, high = n-1;
        while(mid<=high){
            if( nums[mid] == 0){
                swap( nums[low], nums[mid]);
                mid++;
                low++;
            } else if( nums[mid] == 1){
                mid++;
            } else{
                swap( nums[high] , nums[mid]);
                high--;
            }
        }
    }
};
