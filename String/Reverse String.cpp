/* Author : Vansh Kumar
  Date : 2026-01-26
  Description: Leetcode problem-344
*/
class Solution {
public:
    //helper function
    // void reverse( vector<char>& s , int left , int right){
    //     while(left <= right){
    //         swap(s[left] , s[right]);
    //         reverse(s , left+1, right-1);
    //     }
    // }
    void reverseString(vector<char>& s) {
      //wtih recursion
        // reverse( s , 0 , s.size()-1);

    //WITHOUT RECURSION METHOD.
        int st = 0, end = s.size()-1;
        while(st < end){
            swap( s[st++], s[end--]);
        }
    
    }
};
