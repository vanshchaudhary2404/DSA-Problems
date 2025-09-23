#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> & arr , int l , int r){
  if( l >= r)
    return;
  swap( arr[l] , arr[r]);
  return reverseArray( arr , l+1, r-1 );

}

int main(){
  vector<int> arr = {6, 5, 3, 2, 1};
  int n = arr.size();
  int leftPtr = 0;
  int rightPtr = n-1;
  
  reverseArray( arr , leftPtr , rightPtr);

   cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

  return 0;
}
