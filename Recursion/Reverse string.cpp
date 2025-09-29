/* Author : Vansh Kumar
  Date : 2025-09-29
  Description: leetcode problem (344) Reverse String.
*/
class Solution {
public:
//helper function
    void reverse( vector<char>& s , int left , int right){
        while(left <= right){
            swap(s[left] , s[right]);
            reverse(s , left+1, right-1);
        }
    }
    void reverseString(vector<char>& s) {
        reverse( s , 0 , s.size()-1);
    }
};
