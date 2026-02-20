/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-1614. Maximum Nesting Depth of the Parentheses
*/
class Solution {
public:
    int maxDepth(string s) {
        int openBracket =0;
        int res = 0;
        for( char &ch : s){
            if( ch == '('){
                openBracket++;
            }else if( ch == ')'){
                openBracket--;
            }
            res = max(openBracket , res);
        }
        return res;
    }
};
