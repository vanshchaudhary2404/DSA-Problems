#include<iostream>
using namespace std;

int fibo(int n){
  if(n <= 1) //Base case
    return n;
  return fibo(n-1) + fibo(n-2);//Recursive calls
}

int main(){
  cout<<"Enter the number : ";
  int n;
  cin>>n;
  cout<<(fibo(n));
  return 0;
}