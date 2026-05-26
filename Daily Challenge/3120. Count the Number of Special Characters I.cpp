class Solution {
public:
//t.c = o(n+26)
//s.c = o(26*2)
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,-1) , upper(26,-1);
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(islower(ch)){
                lower[ch-'a'] = i;
            }else if(upper[ch-'A'] == -1) upper[ch-'A'] = i;
        }

        int ans =0;
        for(int ch =0; ch<26; ch++){
            if(lower[ch] != -1 && upper[ch] != -1 ){
                ans++;
            }
        }
        return ans;
    }
};
