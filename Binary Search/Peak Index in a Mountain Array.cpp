/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: Leetcode problem-852. Peak Index in a Mountain Array
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st =1, end = arr.size()-2;

        while( st<= end){
            int mid = st + (end - st)/2;
            if( arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }
            
            //lie in inc. val.
            if( arr[mid-1] < arr[mid]){
                st = mid+1;//right Search
            }
            //lie in dec. val
             else {
                end = mid-1; // Left Search
            }
        }
        return -1;
    }
};
