/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-3. Longest Substring Without Repeating Characters
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //Approach 2 using hashing and 2 loops
        /*int n = s.length();
        int maxLen =0;

        for(int i=0; i<n; i++){
            int hash[256] ={0};
            for(int j=i; j<n; j++){
                if(hash[s[j]] == 1){
                    break;
                }
                hash[s[j]] = 1;
                maxLen = max(maxLen , j-i+1);
            }
        }
        return maxLen;*/


        //Approach 3
        vector<int> hash(256, -1);  
        int n = s.size();
        int l =0 , r = 0 , maxLen = 0;
        while( r < n){
            if( hash[s[r]] != -1){//in the map
                if( hash[s[r]] >= l){
                    l = hash[s[r]] +1;
                }
            }
            int len = r - l+1;
            maxLen = max(maxLen , len);
            hash[s[r]] = r;
            r++;
        }

        return maxLen;
    }
};
