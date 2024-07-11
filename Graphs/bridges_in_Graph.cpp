#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nb : adj[node]) {
        if (nb == parent) {
            continue;
        }
        if (!vis[nb]) {
            dfs(nb, node, timer, disc, low, result, adj, vis);
            low[node] = min(low[node], low[nb]);
            if (low[nb] > disc[node]) {
                result.push_back({node, nb});
            }
        } else {
            low[node] = min(low[node], disc[nb]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<vector<int>> result;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(i, -1, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}


int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        vector<int> edge;
        edge.push_back(u);
        edge.push_back(v);
        edges.push_back(edge);
    }
    vector<vector<int>> ans = findBridges(edges, v, e);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}