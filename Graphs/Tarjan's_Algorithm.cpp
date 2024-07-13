#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;
//template<typename T>
#define f(n) for(int i=0;i<n;i++)
#define fr(i,n) for(int i=n-1;i>=0;i--)
#define ff(i,a,b) for(int i=a;i<b;i++)
#define frf(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define ll long long
#define vT vector<T>
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/__gcd(a,b)
#define mod 1000000007
void i_o_f(){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif
}

void dfs(int node, int parent, unordered_map<int, list<int>> &adj, vector<int> &disc, vector<int> &low, unordered_map<int,bool> &vis, vector<int> &ap, int &timer){
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int children = 0;
    for(auto i:adj[node]){
        if(i==parent) continue;
        if(!vis[i]){
            children++;
            dfs(i,node,adj,disc,low,vis,ap,timer);
            low[node] = min(low[node],low[i]);
            if(low[i]>=disc[node] && parent!=-1){
                ap[node] = 1;
            }
        }else{
            low[node] = min(low[node],disc[i]);
        }
    }
    if(parent==-1 && children>1){
        ap[node] = 1;
    }
}

int main(){
    i_o_f();
    unordered_map<int, list<int>> adj;
    vector<pair<int,int>> edges;
    int n = 5;
    int e = 5;
    edges.push_back({0,1});
    edges.push_back({1,2});
    edges.push_back({2,0});
    edges.push_back({0,3});
    edges.push_back({3,4});




    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer =0;
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    unordered_map<int,bool> vis;
    vector<int> ap(n,0);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,adj,disc,low,vis,ap,timer);
        }
    }

    cout<<"Articulation Points are: ";
    for(int i=0;i<n;i++){
        if(ap[i]){
            cout<<i<<" ";
        }
    }



return 0;
}