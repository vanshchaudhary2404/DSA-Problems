/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-1021. Remove Outermost Parentheses
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth =0;
        string res ="";

        for(char ch : s){
            if( ch == '('){
                //if d >0 it is not outermost 
                if(depth>0){
                    res += ch;
                }
                depth++;
            }else{//ch == ')'
                depth--;
                
                //id d>0 after decrement it is not outermost.
                if(depth>0){
                    res += ch;
                }
            }
        }
        return res;
    }
};
