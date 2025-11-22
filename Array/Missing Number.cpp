/* Author : Vansh Kumar
  Date : 2025-10-15
  Description: leetcode- 268. Missing Number
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {

        //Brute force t.c =O(n^2) , s.c = O(1)
        /*for(int i=1; i<=nums.size(); i++){
            int flag = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j] == i){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return i;
        }
        return 0;*/


      // Bettrer approach -> Using hashmap    

      //Optimal (a) -> using Sum
      
      //Optimised : (b) -> Using XOR t.c =O(n) , s.c = O(1)
        /*int XOR1 = 0 , XOR2= 0;
        for(int i=1; i<=nums.size(); i++){
            XOR1 = XOR1^i;
        }
        for(int i=0; i<nums.size(); i++){
            XOR2 = XOR2 ^ nums[i];
        }
        return XOR1^XOR2;*/

        //Optimised above code with one for loop.
        int XOR1 = 0 , XOR2 = 0;
        int n = nums.size();
        for(int i=0; i < n; i++){
            XOR2 = XOR2 ^ nums[i];
            XOR1 = XOR1 ^ i;
        }
        XOR1 = XOR1 ^ n;
        return XOR1 ^ XOR2;
    }
};
