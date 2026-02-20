/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-14. Longest Common Prefix

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        sort(strs.begin() , strs.end());

        string first = strs.front();
        string second = strs.back();
        int i=0;
        while( i< first.size() && i < second.size() && first[i] == second[i]){
            i++;
        }

        return first.substr(0,i);
    }
};
