/* Author : Vansh Kumar
  Date : 2025-09-22
  Description: Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2001] ={0};

        for(int i=0; i<arr.size(); i++){
            freq[arr[i]+ 1000]++;
        }
        vector<int> countList;
        for(int i=0; i<2001; i++){
            if( freq[i] != 0){
                countList.push_back(freq[i]);
            }
        }
        sort(countList.begin() , countList.end());

        for(int i=1; i<countList.size(); i++){
            if( countList[i] == countList[i-1]){
                return false;
            }
        }
        
        return true;
    }
};
