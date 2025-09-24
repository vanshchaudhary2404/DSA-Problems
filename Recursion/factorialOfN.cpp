/* Author : Vansh Kumar
  Date : 2025-09-24
  Description: Factorial of N using recursion 
*/
#include<iostream>
using namespace std;

int fact(int n){
  if(n <= 1)
    return 1;

  return n * fact(n-1);
}

int main(){
  cout<< "Enter the number : ";
  int n;
  cin>> n;
  cout<< (fact(n)) <<" ";
  
  return 0;
}