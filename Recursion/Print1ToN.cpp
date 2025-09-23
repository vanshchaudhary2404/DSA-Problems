/* Author : Vansh Kumar
  Date : 2025-09-23
  Description: Print 1 to n without using loops
*/
class Solution {
  public:
    void printTillN(int n) {
        // code here
        if(n == 0)
            return;
        printTillN( n - 1);
        cout<< n <<" ";
    }
};
