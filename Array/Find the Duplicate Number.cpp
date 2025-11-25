/* Author : Vansh Kumar
  Date : 2025-11-26
  Description: Leetcode problem-287. Find the Duplicate Number
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Brute force T.C =O(n) , S.C = O(n)
        /*unordered_set<int> s;
        for(int val : nums){
            if(s.find(val) != s.end()){
                return val;
            }
            s.insert(val);
        }
        return -1;*/

        //Optimal Uisng slow and fast pointer;
        int slow = nums[0] , fast = nums[0];

        do{
            slow = nums[slow];//+1
            fast = nums[nums[fast]];//+2
        } while( slow != fast);
        slow = nums[0];
        while( slow != fast){
            slow = nums[slow];//+1
            fast = nums[fast];//+1
        }

        return slow;

    }
};
