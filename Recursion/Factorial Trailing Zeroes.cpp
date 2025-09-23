/* Author : Vansh Kumar
  Date : 2025-09-24
  Description: Factorial Trailing Zeroes
*/
#include<iostream>
using namespace std;

int trailingZeroes(int n) {
  if(n < 5)
   return 0;
  if( n == 5)
     return 1;
  return (n / 5) + trailingZeroes( n / 5);
  
}

int main(){
  cout<< "Enter the number:  ";
  int n;
  cin>>n;
  cout<< (trailingZeroes(n));
  return 0;
}
