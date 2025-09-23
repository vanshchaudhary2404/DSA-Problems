/* Author : Vansh Kumar
  Date : 2025-09-23
  Description: Sum of Natural Numbers
*/
class Solution {
  public:
    int findSum(int n) {
        if(n == 0)//Base Case
            return 0;
        return n + findSum(n-1);//Recursivee Calls
    }
};
