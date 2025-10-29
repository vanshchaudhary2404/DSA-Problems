/* Author : Vansh Kumar
  Date : 2025-10-30
  Description: Leetcode problem-217 Contains Duplicate.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    //Approach 1: Brute Force (O(n²))
    /*for(int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
    }*/

    //Approach 2: Sort and Check Adjacent (O(n log n))
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) return true;
    }
    return false;
    }
};
