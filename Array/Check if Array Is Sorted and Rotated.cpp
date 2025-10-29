//Eeasy Leetcod problem-1752  Check if Array Is Sorted and Rotated.
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
       
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            //if (count > 1) return false;  // More than one break point → not valid
        }
        
        return count<=1;
    }
};
