/* Author : Vansh Kumar
  Date : 2025-08-04
  Description: BFS & DFS on Graph in vs code.
*/
#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
  int V;
  list<int>* l; //int * arr

public: 

  //Constructor
  Graph(int V){
    this->V = V;
    l = new list<int> [V]; //arr = new int[V];
  }

  void addEdge(int u  , int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }

  void printAdjList(){
    for(int i=0; i<V; i++){
      cout<< i <<" : ";
      for(int neigh : l[i]){
        cout<< neigh <<" ";
      }
      cout<< endl;
    }
  }


  //Code for BFS Traversal;
  //u->sorce & v->destination
  //T.c = O(V+E)
  void bfs(){
    queue<int> q;
    vector<bool> vis(V,false);

    q.push(0);
    vis[0] = true;

    while(q.size() > 0){
        int u = q.front();
        q.pop();

        cout<< u <<" ";

        for(int v : l[u]){
          if(!vis[v]){
            vis[v] = true;
            q.push(v);
          }
        }
    }
    cout << endl;
  }


  //Code for DFS Traversal;
  //u->sorce & v->destination
  //T.c = O(V+E)
  void dfsHelper(int u , vector<int>& vis){
    cout<< u <<" ";
    vis[u] = true;

    for(int v : l[u]){
      if(!vis[v]){
        dfsHelper(v, vis);
      }
    }
  }
  
  void dfs(){
    int src = 0;
    vector<int> vis(V, false);
    dfsHelper(src , vis);
    cout<<endl;
  }

  //For connected component problem
  /*void dfs(){
    int src = 0;
    vector<int> vis(V, false);
    
    for(int i=0; i<V; i++){
      if(!vis[i]){
          dfsHelper(i , vis);//i -> source
      }
    }
    cout<<endl;
  }
  */

};

int main(){
    Graph g(5);
  
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    // g.addEdge(2,3);
    g.addEdge(2,4);
  
    //g.printAdjList();
    cout<< "BFS: ";
    g.bfs();
  
    cout<<"DFS: ";
    g.dfs();
  return 0;
}
