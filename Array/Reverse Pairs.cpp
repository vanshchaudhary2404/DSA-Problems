/* Author : Vansh Kumar
  Date : 2025-12-04
  Description: Leetcode problem-493. Reverse Pairs
*/
class Solution {
public:
    //Brute Force : T.C -> O(n^2).
    /*int reversePairs(vector<int>& nums) {
        int cnt =0;
        int n= nums.size();
        for(int i=0; i< n; i++){
            for(int j=i+1; j<n; j++){
                if( nums[i] > 2*nums[j]){
                    cnt++;
                }
            }
        } 
        return cnt;
    }*/

    //Optimal Approach T.C-> O(). S.C -> O().
    void merge( vector<int>&arr, int st ,int mid , int end){
          vector<int> temp;
          int i = st , j = mid+1;
          while( i <= mid && j <= end){
            if( arr[i] <= arr[j]){
              temp.push_back(arr[i]);
              i++;
            } else{
              temp.push_back(arr[j]);
              j++;
            }
          } 
          // if elements on the left half are still left /
          while( i<=mid){
            temp.push_back(arr[i]);
            i++;
          }
           //  if elements on the right half are still left //
          while( j <= end){
            temp.push_back(arr[j]);
            j++;
          }
           // transfering all elements from temporary to arr //
          for(int idx =0; idx<temp.size(); idx++){
            arr[idx+st] = temp[idx];
          }
    }

    int countPairs( vector<int> &arr , int st , int mid , int end ){
        int right = mid+1;
        int cnt =0;
        for(int i =st; i<= mid; i++){
            while( right <= end && arr[i] > (long long)2*arr[right]){
                right++;
            }
            cnt += (right - (mid+1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr , int st , int end){
          int cnt = 0;
          if(st >= end) return cnt;
            int mid = st + (end-st)/2;
        
            cnt += mergeSort(arr , st , mid);//Left half
            cnt += mergeSort(arr, mid+1, end);//right half
            cnt += countPairs( arr , st , mid , end);//Modification
            merge(arr , st , mid , end);//Merging
            return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums , 0 , nums.size()-1);
    }
};
