class Solution {
  public:
    void sortInsert(stack<int> &st , int num){
        //base case
        if(st.empty() || st.top() < num){
            st.push(num);
            return;
        }
        
        int n = st.top();
        st.pop();
        
        //recursive call
        sortInsert(st , num);
        
        st.push(n);
        
    }
    void sortStack(stack<int> &st) {
       //base case 
        if(st.empty()){
            return;
        }
        
        int num = st.top();
        st.pop();
        
        //recursive call;
        sortStack(st);
        
        sortInsert(st , num);
    }
};
