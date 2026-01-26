/* Author : Vansh Kumar
  Date : 2026-01-26
  Description: Leetcode problem-1910
*/
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while( s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part) , part.length());
        }
        return s;
    }
};
