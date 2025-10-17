/* Author : Vansh Kumar
  Date : 2025-10-17
  Description: Subset Sums
  Given a array arr of integers, return the sums of all subsets in the list.  Return the sums in any order.
*/
class Solution {
  public:
    void subSum(vector<int> &arr , int ind , int sum , int N , vector<int>&subsetSum){
        if(ind == N){
            subsetSum.push_back(sum);
            return;
        }
        //Pick ele.
        subSum( arr , ind+1 , sum+arr[ind] , N , subsetSum);
        
        //NotPick
        subSum( arr , ind+1 , sum , N , subsetSum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int N = arr.size();
        vector<int> subsetSum;
        subSum( arr , 0 , 0 , N , subsetSum);
        sort(subsetSum.begin() , subsetSum.end());
        return subsetSum;
    }
};
