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


    void prePareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int,int>> &edges){
        for(int i= 0;i<edges.size();i++){
            int u = edges[i].first;
            int v = edges[i].second;

            adjList[u].insert(v);
            adjList[v].insert(u);
        }
    }

    void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int,bool> &vis, vector<int> &ans, int node){
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);
            for(auto i: adjList[frontNode]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    } 

    vector<int> BFS(int vertex, vector<pair<int,int>> edges){

        unordered_map<int, set<int>> adjList;
        vector<int> ans;
        unordered_map<int,bool> visited;
        prePareAdjList(adjList, edges);
        for(int i = 0;i<vertex;i++){
            if(!visited[i]){
                bfs(adjList, visited, ans, i);
            }
        }
        return ans;
    }

    vector<vector<int>> DFS(int vertex, vector<pair<int,int>> edges){
        unordered_map<int, set<int>> adjList;
        vector<vector<int>> ans;
        unordered_map<int,bool> visited;
        prePareAdjList(adjList, edges);
        vector<int> temp;
        for(int i = 0;i<vertex;i++){
            if(!visited[i]){
                temp.clear();
                dfs(adjList, visited, temp, i);
                ans.push_back(temp);
            }
        }
        return ans;
    }
    void dfs(unordered_map<int, set<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &ans, int node){
        visited[node] = true;
        ans.push_back(node);
        for(auto i: adjList[node]){
            if(!visited[i]){
                dfs(adjList, visited, ans, i);
            }
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