#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> & arr , int i , int n ){
  if( i >= n/2)
    return ;
  swap( arr[i] , arr[n-i-1]);
  return reverseArray(arr , i+1 , n);
}

int main(){
  vector<int> arr = {6, 5, 3, 2, 1};
  int n = arr.size();
  int i = 0;
  
  reverseArray( arr , i , n);

   cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

  return 0;
}