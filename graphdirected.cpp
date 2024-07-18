#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V = 4;
    vector<int> adj[V];
    
    
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);  

    Solution sol;
    if (sol.isCyclic(V, adj)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& st) {
        visited[node] = true;
        st[node] = true;
        for (auto nbr : adj[node]) {
            if (!visited[nbr]) {
                if (dfs(nbr, adj, visited, st)) return true;
            } else if (st[nbr]) {
                return true;
            }
        }
        st[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> st(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, st)) return true;
            }
        }
        return false;
    }
};