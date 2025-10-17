/* Author : Vansh Kumar
  Date : 2025-10-17
  Description: GFG- Pair Sum in a Sorted and Rotated Array
  Given an array of positive elements arr[] that is sorted and then rotated around an unknown point, 
  the task is to check if the array has a pair with sum equals to a given target.
*/
// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int pivot = -1;
        //find pivot element
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                pivot = i;
                break;
            }
        }
        
        int high = pivot == -1 ? n - 1 : pivot; // highhest
        int low = (pivot +1 )% n; //Smallest
        
        //using two ppinter approsch in circular manner
        while( low != high ){
            int pairSum = arr[low] + arr[high];
            
            if( pairSum == target )
                //found
                return true;
            else if ( pairSum > target )
                high = (n + high -1)%n;
            else 
                low= (low+ 1)% n;
        }
        
        //not found
         return false;
    }
};
