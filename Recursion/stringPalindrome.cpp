#include<iostream>
using namespace std;

bool checkPalindrome( string &s , int i , int n){
  if( i >= n/2)
    return true;
  if( s[i] != s[n-i-1])
    return false;
  return checkPalindrome( s, i+1 , n);
}

int main(){
  string s = "anna";
  int n = s.size();
  int i = 0;
  // 1 -> true and 0 -> false.
    cout << checkPalindrome(s, i, n) << endl;
    if (checkPalindrome(s, i, n)) {
        cout << "'" << s << "' is a palindrome." << endl;
    } else {
        cout << "'" << s << "' is not a palindrome." << endl;
    }

  return 0;
}