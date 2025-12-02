/* Author : Vansh Kumar
  Date : 2025-12-02
  Description: Leetcode problem-56. Merge Interval
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //Brute force T>C->O(nlogn) sorting + O(2n)every elments iterating twice.
        /*int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if( !ans.empty() && end <= ans.back()[1]){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if( intervals[j][0] <= end){//check the overlapping 
                    end = max( end , intervals[j][1]);
                } else {
                    break;
                }
            }
            ans.push_back({start , end});

        }
        return ans;*/

        //Optimal approach (removing the double iterating element work)
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if( ans.empty() || intervals[i][0] > ans.back()[1] ){
                ans.push_back(intervals[i]);
            }else {
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
            /*if (arr[i][0] <= ans.back()[1]) {           
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
            } 
            else {
                ans.push_back(arr[i]);
            }*/
        }
        return ans;

    }
};
