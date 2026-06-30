class Solution {
public:
    bool isVowel(char c){
        return (c == 'a' ||c == 'e' || c == 'i' || c == 'o' || c == 'u' );
    }
    long long countVowels(string word) {
        int n = word.length();

        long count =0;
        for( int pos =0; pos<n; pos++){
            if(isVowel(word[pos])){
                count += (long)(n-pos) * (long)(pos+1);
            }
        }
        return count;
    }
};
