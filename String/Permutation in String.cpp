/* Author : Vansh Kumar
  Date : 2026-01-26
  Description: Leetcode problem-567
*/
class Solution {
public:
    bool isFreqSame(int freq1[] , int freq2[]){
        for(int i=0; i<26; i++){
            if( freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        //first create a freq array in which i store freq of s1,size 26 becoz of constraints (s1 and s2 consist of lowercase English letters.) 
        int freq[26] = {0};

        for(int i=0; i<s1.length(); i++){
            freq[ s1[i] - 'a']++;
        }

        // size of window that go on s2 string to match it with s1
        int windSize = s1.length();

        for(int i=0; i<s2.length(); i++){
            int windIdx = 0 , idx =i;
            
            //create windox freq to store the current window value and match it with freq value of s1 
            int windFreq[26] ={0};

            while( windIdx < windSize && idx < s2.length()){
                windFreq[s2[idx]- 'a']++;
                windIdx++; idx++;
            }

            if(isFreqSame( freq , windFreq)){
                return true;
            }
        }
        return false;
    }
};
