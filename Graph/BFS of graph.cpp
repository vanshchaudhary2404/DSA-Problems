/* Author : Vansh Kumar
  Date : 2025-10-04
  Description:  GFG problem-
*/

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        
        vector<bool> visi(V,false);//size of visited array with all node as false means not visi
        queue<int> q;
        q.push(0);
        visi[0] = true;
        
        vector<int> bfs;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            bfs.push_back(node);
            
            for(int neighbour : adj[node]){
                if(!visi[neighbour]){
                    visi[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return bfs;
    }
};
