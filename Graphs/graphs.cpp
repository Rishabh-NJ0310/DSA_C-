#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool directed = false){
        adj[u].push_back(v);
        if(directed){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(const auto& i: adj){
            cout<<i.first<<" -> ";
            for(const auto& j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};


int main(){
    int n, m;
    cout<<"Enter the number of vertices and edges: ";
    cin>>n>>m;

    Graph g;
    cout<<"Enter the edges connection : ";
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v, false);
    }

    g.printGraph();

return 0;
}