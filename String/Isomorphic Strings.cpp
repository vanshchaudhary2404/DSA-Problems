/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-205. Isomorphic Strings
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char ,char> mp1;
        unordered_map<char ,char> mp2;

        int m = s.length();
        for(int i=0; i<m; i++){
            int ch1 = s[i];
            int ch2 = t[i];
            //ch1 present in mp1 AND not map in ch2 ||ch2 present in mp2 AND not map in ch1
            if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 ||
                mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1){
                    return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};
