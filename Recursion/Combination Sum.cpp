/* Author : Vansh Kumar
  Date : 2025-10-12
  Description: leetCode Problem-39. Combination Sum.
*/
class Solution {
public:
    set<vector<int>> s;
    void getAllCombin(vector<int>& arr, int idx ,  int tar , vector<vector<int>> &ans,   vector<int> &combin){
        if( idx == arr.size() || tar < 0){
            return;
        }
        if( tar == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
            
        }
        combin.push_back(arr[idx]);
        //Single inclusion
        getAllCombin( arr , idx+1 , tar-arr[idx] , ans , combin);
        //Multi inclusion
        getAllCombin( arr , idx , tar-arr[idx] , ans , combin);
        //Backtracking
        combin.pop_back();
        //Exclusion
        getAllCombin( arr , idx+1 , tar , ans , combin);
    } 

    // candidates -> arr
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombin(arr , 0 , tar , ans , combin);
        return ans;
    }
};
