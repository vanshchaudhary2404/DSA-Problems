/* Author : Vansh Kumar
  Date : 2025-30-03
  Description: Leetcode problem-424. Longest Repeating Character Replacement
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
         vector<int> hash(26,0);
        int l =0, maxFreq= 0, maxLen = 0;
        for( int r= 0; r<s.length(); r++){
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq , hash[s[r]-'A']);
            while( (( r-l+1) - maxFreq) > k){//shrink wind. from left side
                hash[s[l]-'A']--;
                l++;
            }
            maxLen = max( maxLen ,  r-l+1);
        }
        return maxLen;
    }
};
