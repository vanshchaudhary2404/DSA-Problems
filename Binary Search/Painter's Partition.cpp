/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: Hacker Earth problem- 
  Link- https://www.hackerearth.com/problem/algorithm/painters-partition/
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isPossible(vector<int>&arr , int n , int m , int maxAllowedTime ){//T.C -> O(n)
  int painters = 1, time =0;
  for(int i=0; i<n; i++){
    if( time + arr[i] <= maxAllowedTime){
      time += arr[i];
    }else{//new painter added
      painters++;
      time = arr[i];
    }
  }
  return painters<= m ? true:false;
}

int maxTimeToPaint(vector<int>&arr , int n, int m){//O(log(sum) * n)
  int sum = 0 , maxVal = INT_MIN;
  for(int i=0; i<n; i++){//O(n)
    sum += arr[i];
    maxVal = max(maxVal, arr[i]); 
  }

  int st = maxVal, end = sum, ans =-1;
  while( st <=end){//O(log(sum) * n)
    int mid = st + (end - st)/2;
    if(isPossible(arr, n ,m ,mid)){//left
      ans = mid;
      end = mid-1;
    }else{//right
      st = mid+1;
    }
  }
  return ans;
}

int main(){
  vector<int> arr = {40, 30, 10, 20};
  int n= arr.size(), m = 2;

  cout<< maxTimeToPaint( arr , n, m )<<endl;
}
