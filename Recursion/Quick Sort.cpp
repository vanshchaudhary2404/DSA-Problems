/* Author : Vansh Kumar
  Date : 2025-10-19
  Description: Quick Sort 
*/
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr , int st ,int end){
  int idx = st-1, pivot = arr[end];
  //for arranging smaller ele. on pivot left side.
  for(int j=st; j<end; j++){
    if(arr[j] <= pivot){
      idx++;
      swap(arr[j] , arr[idx]);
    }
  }
  //To asssign pivot posiiton
  idx++;
  swap(arr[end] , arr[idx]);
  return idx;
}

void quickSort(vector<int> &arr , int st , int end){
  if( st < end){
    int pivotIndx = partition( arr , st , end);

    quickSort( arr , st , pivotIndx-1);//Left half
    quickSort( arr , pivotIndx+1 , end);//Right half
  }
}

int main(){
  vector<int> arr = {12, 31, 35, 8, 32, 17};
  quickSort( arr, 0 , arr.size()-1);

  for(int val: arr ){
    cout<< val <<" ";
  }
  cout<< endl;
  return 0;
}
