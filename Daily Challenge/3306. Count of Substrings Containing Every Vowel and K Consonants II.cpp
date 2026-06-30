class Solution {
public:
    bool isVowel(char c){
        return (c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u');
    }
    long long countOfSubstrings(string word, int k) {
        //Brute force got TLE
        /*int n = word.size();
        long long ans = 0;

        for(int i=0; i<n; i++){
            unordered_map<char , int> freq;
            int consonents = 0;

            for(int j=i; j<n; j++){
                if(isVowel(word[j])){
                    freq[word[j]]++;
                }else{
                    consonents++;
                }
                if(freq.size() == 5 && consonents == k){
                    ans++;
                }

            }
        }   

        return ans;
        */


        //Approach 2 -> Sliding window
        //for every index, I must know where is the next consonent
        int n = word.size();

        unordered_map<char , int> mp; //for vowel current window  //O(5)

        //preprocessing to be able to find of just next consonant
        vector<int> nextCons(n);//S.C -> O(n)
        int lastConsIdx =n;
        for(int i=n-1; i>=0; i--){//O(n)
            nextCons[i] = lastConsIdx;
            if(!isVowel(word[i])){
                lastConsIdx = i;
            } 
        }

        int i=0;
        int j=0;
        long long count = 0;
        int cons = 0;
        //O(2*n) -> O(n)
        while(j < n){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }else{
                cons++;
            }

            //consonent count must be >= k invalid reason
            while(cons > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;
            }

            //valid window
            while(i<n && mp.size() == 5 && cons == k){
                int idx = nextCons[j];//it will tell the next consonent after jth idx 
                count += idx-j;//most important part
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;
            }
            j++;
        }

        return count;
    }
}; 
