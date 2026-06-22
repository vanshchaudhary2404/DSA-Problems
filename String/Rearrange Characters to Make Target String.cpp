class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int t[26] = {0};
        int count[26] = {0};
       
        for(const char& ch : target){
            t[ch-'a']++;
        }
        for(const char& ch : s){
            count[ch -'a']++;
        }
        int ans = INT_MAX;
        for(char c : target){
            ans = min(ans , count[c-'a']/t[c - 'a']);
        }

        return ans;
    }
};
