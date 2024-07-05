#include<bits/stdc++.h>  // only for competitive programming not for developing
using namespace std;
template<typename T>
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

class Graph{
    public:
    unordered_map<int, list<pair<int, int>>> adj;
    
    // for Direct Acyclic Weighted Graph
    void addEdge(int u, int v, int weight){
        pair<int,int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<") ";
            }
            cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int,bool> &visited, stack<int>&s){
        visited[node] = true;
        for(auto n: adj[node]){
            if(!visited[n.first]){
                dfs(n.first, visited, s);
            }
        }

        s.push(node);
    }

    void getShortestPath(int src, vector<int> &dist, stack<int> &s){
        dist[src] = 0;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            if(dist[top] != INT_MAX){
                for(auto i: adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};


int main(){

// i_o_f();
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,3,6);
    g.addEdge(1,2,2);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(2,3,7);
    g.addEdge(3,5,1);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    g.printAdj();


    // topological sort
    int n = 6;
    stack<int> s;
    unordered_map<int, bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i, visited, s);
        }
    }
    int src = 1;
    vector<int> distance(n);
    for(int i=0;i<n;i++){
        distance[i] = INT_MAX;
    }

    g.getShortestPath(src, distance, s);
    cout<<"Shortest Path from "<<endl;

    for(auto i: distance){
        cout<<i<<" ";
    }
return 0;
}