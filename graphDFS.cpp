#include <iostream>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        V = v;
        l = new list<int> [V];
    }
    void addEdge(int i , int j, bool undire = true){
        l[i].push_back(j);
        if(undire){
            l[j].push_back(i);
        }
    }
    void dfshelper(int node , bool *visited){
          cout<<node<<endl;
          visited[node] = true;
          for(auto nbr : l[node]){
             if(!visited[nbr]){
                dfshelper(nbr,visited);
             }
          }
          return;
    }
    void DFS(int source){
        bool *visited = new bool[V]{0};
        dfshelper(source,visited);
    }
    
};


int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.DFS(1);
    




    return 0;
}
