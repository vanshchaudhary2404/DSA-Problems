//Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.
//You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.empty())
         return {};
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if( nums[abs(nums[i])-1] < 0){
                ans.push_back(abs(nums[i]));
            } else{
                nums[abs(nums[i]) -1] = - nums[abs(nums[i]) - 1];
            }
        }
        return ans;
    }
}; 
