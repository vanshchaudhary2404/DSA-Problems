/* Author : Vansh Kumar
  Date : 2025-09-30
  Description: Gfg- M coloring problem.
  You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.
  Note: The graph is indexed with 0-based indexing.
  Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
  Output: true
  Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:
*/
class Solution {
  public:
     bool isSafe(int c,int n,vector<int>&color,vector<vector<int>>&adjList){
       
       for(auto it : adjList[n]){
           if(color[it]==c) return false;
       }
       return true;
   }
    bool dfs(vector<vector<int>>&adjList, int m , int v ,vector<int>&color,int node ){
        if(v==node) return true;
       
       for(int i = 1 ;i <= m ;i++){
           
           if(isSafe(i,node,color,adjList)){
               color[node] = i;
               if(dfs(adjList,m,v,color,node+1)) return true;
               color[node] = 0;
           }
       }
       return false;
        
    }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adjList(v);
        for( auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<int>color(v,-1);
         return dfs(adjList,m,v,color,0);      
    }
};
