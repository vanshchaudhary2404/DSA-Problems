/* Author : Vansh Kumar
  Date : 2026-01-26
  Description: Leetcode problem-125
*/
class Solution {
public:
//“I use a two-pointer approach, skipping non-alphanumeric characters and comparing lowercase characters
// from both ends in O(n) time and O(1) space.”
    bool isPalindrome(string s) {
        int st = 0 , end = s.size()-1;

        while( st < end){
            if(!isalnum(s[st])){
                st++; continue;
            }
            if(!isalnum(s[end])){
                end--; continue;
            }
            if( tolower(s[st]) != tolower(s[end])){
                return false;
            } 
            st++;
            end--;
        }
        return true;
    }
};
