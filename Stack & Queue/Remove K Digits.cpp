/* Author : Vansh Kumar
  Date : 2025-13-02
  Description: Leetcode problem-402. Remove K Digits
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        int n = num.size();
        for(int i=0; i<n; i++){
            while(!s.empty() && k >0 && (s.top()- '0') > (num[i]- '0')){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        //when k left it remove all last k values from stack
        while( k > 0){ s.pop(); k--; }
        //if stack left with 0 or it is empty
        if(s.empty()) return "0";

        string res = "";
        while(!s.empty() ){
            res += s.top();
            s.pop();
        }

        //Removing the leading/trailing zeros
        while( res.size() !=0 && res.back() == '0'){
            res.pop_back();
        }
        reverse(begin(res) , end(res));
        if(res.empty()) return "0";
        return res;
    }
};
