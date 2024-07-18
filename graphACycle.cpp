#include <iostream>
#include<list>
#include<vector>
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
   bool dfs(int node, vector<bool> &visited, int parent) {
        visited[node] = true;
        for (auto nbr : l[node]) {
            if (!visited[nbr]) {
                bool foundCycle = dfs(nbr, visited, node);
                if (foundCycle) return true;
            } else if (nbr != parent) {
                return true;
            }
        }
        return false;
    }
    bool isCycle() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
   
};


int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    
    
    if (g.isCycle()) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
    




    return 0;
}
