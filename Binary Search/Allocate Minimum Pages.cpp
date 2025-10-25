/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: GFG problem- Allocate Minimum Pages
  link - https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
*/
class Solution {
  public:
  
bool isValid( vector<int>&arr , int n , int m ,int maxAllowedPages){//O(n)
  int stu = 1, pag = 0;

  for(int i=0; i<n; i++){
    if( arr[i] > maxAllowedPages){
      return false;
    }
    if(pag + arr[i] <= maxAllowedPages){
        pag += arr[i];
    } else{
      stu++;
      pag = arr[i];
    }
  }

  return stu > m ? false : true;
}

int allocateBooks(vector<int> &arr , int n , int m  ){//O(logn N *n)
  if( m >n){
    return -1;
  }
  int sum =0;
  for(int i=0; i<n; i++){//O(n)
    sum += arr[i];
  }
  int ans =-1;
  int st =0 , end = sum;//Range of possible ans

  while(st <= end){//O(logN)
    int mid = st + (end -st)/2;
    if( isValid(arr , n , m , mid)){//left
      ans = mid;
      end = mid-1;
    } else {//right
      st = mid+1;
    }
  }
  return ans;
}

    int findPages(vector<int> &arr, int m) {
        // code here
        int n = arr.size();
        return allocateBooks(arr , n , m );
    }
};
