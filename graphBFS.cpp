#include<iostream>
#include<list>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        V = v;
        l = new list<int>[V];

    }
    void addEdge(int i , int j, bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
       
    }
    void BFS(int startNode){
        queue<int> q;
        q.push(startNode);
        bool *visited = new bool[V]{0};
        visited[startNode] = true;
        while(!q.empty()){
            int f = q.front();
            q.pop();
            cout<<f<<endl;
            for(auto nbr : l[f]){
                if(visited[nbr]==false){

                q.push(nbr);
                visited[nbr] = true; 
                }
            }
        }

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

    g.BFS(0);

    return 0;
}