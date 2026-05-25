class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> visited(n,false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        int farthest = 1;
        
        while(!q.empty()){

            int curr = q.front();
            q.pop();

            if(curr == n-1) return true;

            int st = max(curr + minJump , farthest);
            int end = min(curr + maxJump , n-1);

            for(int i=st; i<=end; i++){
                if( s[i]=='0' && !visited[i] ){
                    visited[i] = true;
                    q.push(i);
                }
            }
            farthest = end+1;
        }
        return false;
    }
};
