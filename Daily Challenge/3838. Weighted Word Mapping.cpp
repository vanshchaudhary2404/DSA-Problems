class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for(string &word : words){
            long long temp =0;
            for(char &ch : word){
                temp += weights[ch-'a'];
            }
            res += 'z'- temp%26;
        }
        return res;
    }
};
