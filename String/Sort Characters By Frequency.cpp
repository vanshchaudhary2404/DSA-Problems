/* Author : Vansh Kumar
  Date : 2025-20-02
  Description: Leetcode problem-451. Sort Characters By Frequency
*/
class Solution {
public:
typedef pair<char , int> P;
    string frequencySort(string s) {
        vector<P> vec(123);

        for(auto &ch : s){
            int freq = vec[ch].second;
            vec[ch] = {ch , freq+1};
        }

        //Sort
        auto lambda = [&](P &p1 , P &p2){
            return p1.second > p2.second; 
        };
        sort( begin(vec) , end(vec) , lambda);

        string res = "";
        for( int i=0; i<=122; i++){
            if(vec[i].second > 0){
                char ch = vec[i].first;
                int freq = vec[i].second;
                string temp = string(freq, ch);//size . character.

                res += temp;
            }
        }
        return res;
    }
};
