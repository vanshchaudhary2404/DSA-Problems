/* Author : Vansh Kumar
  Date : 2025-10-29
  Description: Leetcode problem-50. Pow(x, n).
*/
class Solution {
public:
    // double myPow(double x, int n) {
        
    //     if(n == 0) return 1.0;
    //     if(x == 0) return 0.0;
    //     if(x == 1) return 1.0;
    //     if(x == -1 && n%2 == 0) return 1.0;
    //     if(x == -1 && n%2 != 0) return -1.0;

    //     long binForm = n;
    //     if( n < 0){
    //         x = 1/x;
    //         binForm = -binForm;
    //     }
    //     double ans =1;
    //     while(binForm > 0){
    //         if(binForm % 2 == 1){
    //             ans *= x;
    //         }
    //         x *= x; // x^2
    //         binForm /= 2;
    //     }
    //     return ans;
    // }
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
