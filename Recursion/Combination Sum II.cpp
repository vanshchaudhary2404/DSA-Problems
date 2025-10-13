/* Author : Vansh Kumar
  Date : 2025-10-13
  Description: Leetcode-40. Combination Sum II.
*/
class Solution {
public:
    void getAllComb( vector<int>& candidates , int idx , int tar , vector<vector<int>> &ans , vector<int> &combin){
        if( tar == 0){
            ans.push_back(combin);
            return;
        }
        for(int i = idx; i< candidates.size(); i++){
            if( i > idx && candidates[i] == candidates[i-1]) continue;
            if( candidates[i] > tar) break;
            combin.push_back(candidates[i]);
            //single inclusion
            getAllComb( candidates , i +1 , tar-candidates[i] , ans , combin);
            //Backtrack
            combin.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> combin;
        getAllComb( candidates , 0 , target , ans , combin);

        return ans;
    }
};
