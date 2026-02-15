/* Author : Vansh Kumar
  Date : 2025-15-02
  Description: GFG problem- Reverse first k of a Queue.
*/
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if (q.empty() || k <= 0 || k > q.size())
            return q;

        int n = q.size();
        int remain = n-k;
        
        stack<int> st;
        
        while(k>0){
            st.push(q.front());
            q.pop();
            k--;
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        while( remain >0){
            q.push(q.front());
            q.pop();
            remain--;
        }
        return q;
    }
};
