/* Author : Vansh Kumar
  Date : 2025-09-25
  Description: Pow(x, n) 
  Leetcode problem - 50.
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n ==0)
            return 1;
    long long num = n;
    if (num < 0) {
        x = 1 / x;
        num = -num;
        return pow( x, num);
    }
    
    double half = pow(x , n/2);

    if ( n %2 == 0)
        return half * half;
    else 
        return x * half * half;
    }
};
