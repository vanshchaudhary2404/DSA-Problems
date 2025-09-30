/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: Leetcode problem 90. Subsets II
              Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
              The solution set must not contain duplicate subsets. Return the solution in any order.
*/
class Solution {
public:
    void getAllSubsets(vector<int>& nums , vector<int> &ans , int i , vector<vector<int>> &allSubsets){
        //Base case
        if( i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }
        //Include
        ans.push_back(nums[i]);
        getAllSubsets( nums , ans , i+1 , allSubsets);
        //Backtracking
        ans.pop_back();
        //Avoid Duplication
        int indx = i+1;
        while(indx < nums.size() && nums[indx] == nums[indx-1]){
            indx++;
        }
        //Exclude
        getAllSubsets( nums , ans , indx , allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<vector<int>> allSubsets;
        getAllSubsets( nums , ans , 0 , allSubsets);
        return allSubsets;
    }
};
