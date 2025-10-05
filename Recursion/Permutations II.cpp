/* Author : Vansh Kumar
  Date : 2025-10-05
  Description: Leetcode Problem-> 47. Permutations II
  Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
*/
class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& ans) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            // skip duplicates: if nums[i] is the same as nums[i-1] and i > start,
            // then we already placed this value at position "start" earlier.
            if (i > start && nums[i] == nums[i-1]) continue;

            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, ans);
            swap(nums[start], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }
    // void backtrack(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    //     if (idx == nums.size()) {
    //         ans.push_back(nums);
    //         return;
    //     }
    //     unordered_set<int> seen;
    //     for (int i = idx; i < nums.size(); i++) {
    //         if (seen.count(nums[i])) continue;
    //         seen.insert(nums[i]);
    //         swap(nums[idx], nums[i]);
    //         backtrack(nums, idx + 1, ans);
    //         swap(nums[idx], nums[i]); // backtrack
    //     }
    // }

    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     backtrack(nums, 0, ans);
    //     return ans;
    // }
};
