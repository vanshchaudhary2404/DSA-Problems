/* Author : Vansh Kumar
  Date : 2026-01-26
  Description: Leetcode problem-152 Reverse Words in a String
*/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans ="";

        reverse(begin(s) , end(s));

        for(int i=0; i<n; i++){
            string word ="";
            //store the single reversed word in word string
            while( i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            //reverse that word string to get correct word order
            reverse( begin(word), end(word));

            if( word.length() > 0){
                ans += " "+ word;
            }
        }
        return ans.substr(1);//to remove the leading space from ans;
    }
};
