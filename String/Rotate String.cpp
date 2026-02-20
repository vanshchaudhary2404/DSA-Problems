/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-796. Rotate String
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        //Approach 1 using rotate STL;
        /*int m = s.length();
        int n = goal.length();
        if(m != n){
            return false;
        }
        for(int i=1; i<=m; i++){
            //rotate s one left shift
            rotate(begin(s) , begin(s)+1 , end(s));
            if( s == goal){
                return true;
            }
        }
        return false;
    */
    
    //Approach 2:using string concatination
        int m = s.length();
        int n = goal.length();
        if(m != n){
            return false;
        }
        if( (s+s).find(goal) != string::npos){
            return true;
        }
        return false;
    }
};
