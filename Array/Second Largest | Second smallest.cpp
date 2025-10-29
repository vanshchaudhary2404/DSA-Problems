/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: GFG problem- Second Largest
  Link - https://www.geeksforgeeks.org/problems/second-largest3735/1
*/
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        if( arr.size() < 2){
            return -1;
        }
        
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
            }
            else if( arr[i] > secondLargest && arr[i] != largest ){
                secondLargest = arr[i];
            }
        }
        
        if( secondLargest == INT_MIN){
            return -1;
        }
        
        return secondLargest;
    }
};


//FOR Smallest 
int getSecondSmallest(vector<int> &arr) {
        // code here
        if( arr.size() < 2){
            return -1;
        }
        
        int smallest = arr[0];
        int secondSmallest = INT_MAX;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] > smallest){
            secondSmallest = smallest;
            smallest = arr[i];
            }
            else if( arr[i] > secondSmallest && arr[i] != smallest ){
                secondSmallest = arr[i];
            }
        }
        
        if( secondSmallest == INT_MAX){
            return -1;
        }
        
        return secondSmallest;
    }
