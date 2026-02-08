/* Author : Vansh Kumar
  Date : 2025-09-02
  Description: Leetcode problem-155
*/
//Approach 1 : S.CO(n) + O(n) // for stack and pair to store second value.
class MinStack {
public:
    stack<pair<int , int>> s; //val, minVal;
    MinStack() {
        
    }
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        } else{
            int minVal = min(val , s.top().second);
            s.push({val , minVal});        
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};


//Approach 2: S.C -O(n)
class MinStack {
public:
    stack<long long int > s;
    long long int minVal;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minVal = val;
        } else{
            if( val < minVal){
                s.push((long long)2*val - minVal);//push in stack
                minVal = val;//value in global minVal;
            }else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top() < minVal){
            minVal = 2*minVal - s.top();
        }
        s.pop();
    }
    
    int top() {
        if( s.top() < minVal){
            return minVal;
        }
        return s.top();
    }
    
    int getMin() {
        return minVal;
    }
};
