/* Author : Vansh Kumar
  Date : 2025-11-28
  Description: Leetcode problem-18. 4Sum
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int tar) {
     a   //Ooptimal APPROACH T.C = O(n^3) + O(nlog n) , S.C = O(k)where k = number of unique quadruplets
        vector<vector<int>> ans;
        int n = arr.size();
        sort(begin(arr), end(arr));
        for(int i=0; i<n; i++){
            if( i>0 && arr[i] == arr[i-1]) continue;

            for(int j=i+1; j<n;){
                int p = j+1 , q = n-1;

                while( p<q){
                    long long sum = (long long)arr[i]  + (long long)arr[j] + (long long)arr[p] + (long long)arr[q];

                    if( sum > tar) q--;
                    else if( sum < tar) p++;
                    else {
                        ans.push_back( {arr[i] , arr[j], arr[p] ,arr[q]});
                        p++;
                        q--;

                        while( p<q && arr[p] == arr[p-1]) p++;
                    }
                }

                j++;
                while( j < n && arr[j] == arr[j-1]) j++;
            }
        }
        return ans;
    }
};
