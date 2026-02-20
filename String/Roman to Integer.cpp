/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-13. Roman to Integer
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char , int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int ans = 0;
        for( int i=0; i<s.length(); i++){
            if(mp[s[i]] >= mp[s[i+1]]){
                ans += mp[s[i]];
            }else{
                ans -= mp[s[i]];
            }
        }
        return ans;
    }
};
