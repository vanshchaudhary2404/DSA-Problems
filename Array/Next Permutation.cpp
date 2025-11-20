/* Author : Vansh Kumar
  Date : 2025-10-15
  Description: leetcode-31. Next Permutation
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //STL Solution
        //next_permutation( nums.begin(), nums.end());

        ///Brute Force Using recursion.

        //Optimised
        int pivot = -1 , n =nums.size();
        //Step 1 : for finding the pivot element 
        for(int i = n-2; i>=0; i--){
            if( nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
        //IF array is already sorted or thrie is no pivot
        if( pivot == -1){
            reverse( nums.begin() , nums.end());
            return;
        }

        //Step 2 : next lexicographically element.
        for(int i= n-1; i>pivot; i--){
            if( nums[i] > nums[pivot]){
                swap(nums[i] , nums[pivot]);
                break;
            }
        }

        //Step 3 : Reverse (pivot+1) to (n-1)
        //reverse( nums.begin() +pivot +1 ,nums.end());
                        //OR
        int i = pivot +1 , j =n-1;
        while( i<= j){
            swap(nums[i++] , nums[j--]);
        }
    }
};
