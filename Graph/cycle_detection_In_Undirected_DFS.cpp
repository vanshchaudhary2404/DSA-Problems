#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
  int V;
  list<int>* l;

public: 
  Graph(int V){
    this->V = V;
    l = new list<int> [V];
  }

  void addEdge(int u , int v){
    l[u].push_back(v);
    l[v].push_back(u);
  }


  //function for cycle detection
  bool isCycleUndirDFS(int src , int par , vector<bool>& vis  ){
    vis[src] = true;
    list<int> neighbour = l[src];

    for(int v: neighbour){
      if(!vis[v]){
        if(isCycleUndirDFS(v , src , vis)){
          return true;
        }
      } else if( v != par){
        return true;
      }
    }
    return false;
  }


  bool isCycle(){
    vector<bool> vis(V,false);

    //for connected component also
    for(int i=0; i<V; i++){
      if(!vis[i]){
        if(isCycleUndirDFS(i , -1 , vis)){
          return true;
        }
      }
    }
    return false;
  }

};


int main(){
  Graph g(5);


  g.addEdge(0,1);
 //g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(1,2);
  g.addEdge(3,4);
  

  if (g.isCycle()) {
    cout << "Cycle detected" << endl;
  } else {
    cout << "No cycle detected" << endl;
  }

  return 0;
}
