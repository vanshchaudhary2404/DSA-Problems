/*
Author : Vansh Kumar
Date: 2025-09-22
Description: Find Majority element in an array
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Brute force approach T.C = O(n)
/*int majorityElement(vector<int>&  nums ){
  int n = nums.size();

  for(int val : nums){
    int freq =0;

    for(int el : nums){
      if( el = val){
        freq++;
      }
    }
    if( freq > n/2)
      return val;
  }
  return -1;
}*/

//Optimized Approach T.C = O(n logn)
/*int majorityElement(vector<int> & nums){
  int n = nums.size();

  sort(nums.begin(), nums.end());
  //frequency count
  int freq = 1 , ans = nums[0];
  for(int i =1; i<n; i++){
     if( nums[i] == nums[i-1]){
      freq++;
     }
     else{
      freq = 1;
      ans = nums[i];
     }
    
     if( freq > n/2){
      return ans;
     }
  }
} */

//Moore's Voting Algorithm(more optimised Approach) T.C = O(n) , S.C = O(1)
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;
        for (int i=0; i<nums.size(); i++) {
            if (freq == 0)
                ans = nums[i];
            if( ans ==  nums[i] )
                freq++;
            else 
                freq--;
        }
        return ans;
    }


int main() {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  cout<< "Majority Eleemnt :  "<< majorityElement(nums) << endl;

  return 0;
}
