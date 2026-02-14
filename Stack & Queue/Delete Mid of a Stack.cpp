/* Author : Vansh Kumar
  Date : 2025-15-02
  Description: Leetcode problem-Delete Mid of a Stack
*/
class Solution {
  public:
    void solve(stack<int>& s ,int cnt , int size){
        //base case 
        if(cnt == size/2){
            s.pop();
            return;
        }
        int n = s.top();
        s.pop();
        cnt++;
        
        //recursive call
        solve( s, cnt , size);
        
        s.push(n);
    }
    
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int cnt =0;
        int n = s.size();
        solve(s , cnt , n);
    }
};
