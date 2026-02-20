/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-242. Valid Anagram
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        //Approach 1 using sorting
        /*if(s.length() != t.length()) return false;

        sort(begin(s), end(s));
        sort(begin(t) , end(t));

        if( s == t){
            return true;
        }
        return false;
        */

        //Approach 2: using freq count hashing using array
        if(s.length() != t.length()) return false;
        vector<int> count(26,0);
        for(int i=0; i<s.length(); i++){
            count[ s[i] - 'a']++;
            count[ t[i] - 'a']--;
        }

        bool allZeros = all_of(begin(count) , end(count) , [](int element){ 
            return element ==0;
        });

        return allZeros;
    }
};
