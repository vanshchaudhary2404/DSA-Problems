/* Author : Vansh Kumar
  Date : 2025-10-01
  Description: Permutations
                Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order. 
  Leetcode problem - 46
*/
class Solution {
public:
    void getPerms( vector<int> &nums , int indx , vector<vector<int>>&ans){
        if(indx == nums.size()){
            ans.push_back({nums});
            return;
        }
        //choices
        for( int i = indx; i < nums.size(); i++){
            //index place => ith element choice
            swap(nums[indx] , nums[i]);
            getPerms( nums , indx+1 , ans);

            //Backtracking
            swap(nums[indx] , nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms( nums , 0 , ans);
        return ans;
    }
};
