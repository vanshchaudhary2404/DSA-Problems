/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: Leetcode problem(78) Subsets : 
                  Given an integer array nums of unique elements, return all possible subsets (the power set).
                  The solution set must not contain duplicate subsets. Return the solution in any order. 
*/
class Solution {
public:
    void getallSubsets(vector<int>& nums, vector<int> &ans , int i, vector<vector<int>> &allSubsets ){
        //Base case
        if(i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        //Include
        ans.push_back(nums[i]);
        getallSubsets( nums , ans , i+1 , allSubsets);

        //Backtracking
        ans.pop_back();

        //Exclude
        getallSubsets( nums , ans , i+1 , allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allSubsets;
        getallSubsets(nums , ans , 0 , allSubsets);
        return allSubsets;
    }
};
