/* Author : Vansh Kumar
  Date : 2025-08-02
  Description: Leetcode problem-20
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if( s[i] == '(' || s[i] == '{' || s[i] == '['){//opening 
                st.push(s[i]);
            }
            else{
                if( st.size() == 0){
                    return false;
                }
                if( (st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']') ){
                    st.pop();
                } else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};
