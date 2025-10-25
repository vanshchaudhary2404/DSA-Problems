/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: AGGRCOW - Aggressive cows
  link- https://www.spoj.com/problems/AGGRCOW/
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * Checks if it is possible to place C cows in N stalls such that the minimum
 * distance between any two cows is at least minAllowedVal.
 *
 * @param arr Vector containing the positions of the stalls (must be sorted).
 * @param N The number of stalls.
 * @param C The number of cows to place.
 * @param minAllowedVal The minimum allowed distance between any two cows.
 * @return True if possible to place all cows with at least minAllowedVal distance, else false.
 */
bool isPossible(vector<int>&arr, int N, int C , int minAllowedVal){
  int cows =1 , lastStallPos= arr[0];
  for(int i=0; i<N; i++ ){
    if(arr[i] - lastStallPos >= minAllowedVal){
      cows++;//place next cows when this condition is true
      lastStallPos = arr[i];
    }

    if(cows == C) return true;
  }
  return false;
}


/**
 * Finds the largest minimum distance possible to place C cows in N stalls such that
 * the minimum distance between any two cows is maximized.
 *
 * The function sorts the stall positions and uses binary search to determine the
 * largest minimum distance that can be achieved.
 *
 * @param arr Vector containing the positions of the stalls.
 * @param N The number of stalls.
 * @param C The number of cows to place.
 * @return The largest minimum distance possible between any two cows.
 *
 * Logic for `st = mid + 1`:
 *   - If it is possible to place all cows with at least `mid` distance apart,
 *     we try to find a larger minimum distance by searching the right half
 *     (i.e., increasing the lower bound to `mid + 1`).
 *
 * Logic for `end = mid - 1`:
 *   - If it is not possible to place all cows with at least `mid` distance apart,
 *     we need to search for a smaller minimum distance by reducing the upper bound
 *     to `mid - 1`.
 */
int getAggresiveCow(vector<int>&arr, int N, int C ){
  sort(arr.begin() ,arr.end());
  int st=1 , end = arr[N-1]- arr[0], ans =-1;
  while( st<= end){
    int mid = st + (end - st)/2;

    if(isPossible(arr, N, C ,mid)){
      ans = mid;
      st= mid+1;//largest min distance possible
    }else{
      end = mid-1;
    }
  }
  return ans;
}

int main(){
  vector<int> arr = { 1, 2, 8, 4, 9};
  int N=5;
  int C =3;

  cout<< getAggresiveCow( arr, N, C)<<endl;
}
