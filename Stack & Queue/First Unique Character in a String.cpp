/* Author : Vansh Kumar
  Date : 2025-13-02
  Description: Leetcode problem-387. First Unique Character in a String
*/
class Solution {
public:
    int firstUniqChar(string s) {
        //Appproach 1 using freq array of size 26 
        //Since only lowercase letters exist → we can use an array of size 26.
        vector<int> freq(26, 0);
        
        // Step 1: Count frequencies
        for(char c : s) {
            freq[c - 'a']++;
        }
        
        // Step 2: Find first unique
        for(int i = 0; i < s.length(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
        
        //Approach 2 USing Queue & Map
        /*
        unordered_map<char , int> m;
        queue<int> q;

        for(int i=0; i<s.size(); i++){
            //if char not exist in map push it and increase freq.
            if( m.find(s[i])== m.end()){
                q.push(i);
            } 
            m[s[i]]++;//increase freq;

            //remove all element
            while( q.size() > 0 && m[s[q.front()]] > 1){
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
        */
    }
};
