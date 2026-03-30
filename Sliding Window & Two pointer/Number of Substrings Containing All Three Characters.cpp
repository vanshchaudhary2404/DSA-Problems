/* Author : Vansh Kumar
  Date : 2025-30-03
  Description: Leetcode problem-1358. Number of Substrings Containing All Three Characters
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
         //Brute Force : t.c = O(n^2) , s.c = O(3)
        /*int count =0;
        int n = s.length();
        for(int i=0; i<n; i++){
            int hash[3] = {0};
            for(int j=i; j<n; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    count += 1;
                }
            }
        }
        return count;
        */
        //Better
        /*int count =0;
        int n = s.length();
        for(int i=0; i<n; i++){
            int hash[3] = {0};
            for(int j=i; j<n; j++){
                hash[s[j] - 'a'] = 1;
                if(hash[0] + hash[1] + hash[2] == 3){
                    //count += 1;
                    count += (n-j);
                    break;
                }
            }
        }
        return count;
        */   

    //Optimize approach : using sliding window.
    int lastSeen[3] = {-1, -1, -1};
    int count = 0;
    int n = s.length();
        for(int i=0; i<n; i++){
            lastSeen[ s[i]-'a'] = i;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                count = count + (1+ min(lastSeen[0] , min(lastSeen[1] , lastSeen[2])));
            }
        }
        return count;
    }
};
