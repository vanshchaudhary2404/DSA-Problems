class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string res ="";
        for(char ch: s){
            if(ch >= 'a' && ch <= 'z'){
                res +=ch;
            }else if( ch == '*' && res.size()>=1){
                res.pop_back();
            }else if(ch == '#' && res.size()>=1){
                string temp = res;
                res += temp;
            }else if(ch == '%') {
                reverse(res.begin() , res.end());
            }
        }

        return res;
    }
};
