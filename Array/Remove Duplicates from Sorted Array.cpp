/* Author : Vansh Kumar
  Date : 2025-10-30
  Description: Leetcode problem-26. Remove Duplicates from Sorted Array.
*/

//brute force T.c-O(n) , S.C - O(n).
//Using set
/*int removeDuplicates(vector<int>& nums) {
    vector<int> temp;
    for (int num : nums) {
        if (temp.empty() || temp.back() != num)
            temp.push_back(num);
    }
    for (int i = 0; i < temp.size(); i++)
        nums[i] = temp[i];
    return temp.size();
}*/


//Optimal approach  T.c-O(n) , S.C - O(1).
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.empty()) return 0;
        int i = 0;//pointer for last unique item.
        for(int j =1; j<nums.size(); j++){
            if(nums[i] !=  nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;//length = index + 1. // number of unique elements
    }
};


//Using STL.
/*#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    return distance(nums.begin(), unique(nums.begin(), nums.end()));
}

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);
    cout << "k = " << k << "\nArray: ";
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
}*/

/* Here:
1. std::unique() moves duplicates to the end and returns an iterator to the new logical end.
  It does not actually erase elements — it just moves unique elements to the front, and returns an iterator to the new logical end of the unique range.
2. distance() computes how many unique elements there are, distance(it1, it2) returns the number of elements between two iterators.
*/
