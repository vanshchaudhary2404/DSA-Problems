/* Author : Vansh Kumar
  Date : 2025-11-24
  Description: leetcode-1.  2Sum
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int tar) {
        //Brute Force : T.C = O(n^2) , S.C = O(1).
        /* for(int i=0; i<a.size(); i++){
            for(int j=i+1; j<a.size(); j++){
                if(a[i] + a[j] == tar){
                    return {i , j};
                }
            }
        }
        return {};*/

        //Better Approach (Using two pointer) : T.C = O(nlogn) + O(n) = O(nlogn) , S.C = O(n).
        /*vector<pair<int,int>> arr;
        int n= a.size();
        for(int i=0; i<n; i++){
            arr.push_back({a[i] , i});
        }
        sort(arr.begin(), arr.end());
        int l = 0, r = n-1;
        while( l<r){
            int sum = arr[l].first + arr[r].first;

            if( sum > tar) r--;
            else if( sum < tar) l++;
            else {
                return {arr[l].second , arr[r].second};
            }
        }
        return {};*/

        //Optimal approahc (Using hashing):T.C = O(n) , S.C = O(n). 
        unordered_map<int , int> mp;
        for(int i=0; i<a.size(); i++){
            int second = tar - a[i];

            if(mp.find(second) != mp.end()){
                return {mp[second] , i};
            }
            mp[a[i]] = i;
        }
        return {};
    }
};
