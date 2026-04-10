/* Author : Vansh Kumar
  Date : 2025-10-04
  Description: GFG problem-DFS of Graph
*/

class Solution {
  public:
    void dfsHelper(int u , vector<vector<int>>& adj , int vis[] , vector<int>& ls){
        vis[u] = 1;
        ls.push_back(u);
        
        for(auto v: adj[u]){
            if(!vis[v]){
                dfsHelper(v , adj , vis , ls);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        int vis[V] =  {0};
        int u = 0;
        vector<int> ls;
        dfsHelper(u , adj , vis , ls);
        return ls;
    }
};
