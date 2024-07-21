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
<<<<<<< HEAD
            q.pop();
=======
>>>>>>> 0b8835cb177ffa5e85f7ef2f196a9d1438d7c2b3
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

<<<<<<< HEAD
    g.BFS(0);
=======
    g.BFS(6);
>>>>>>> 0b8835cb177ffa5e85f7ef2f196a9d1438d7c2b3

    return 0;
}