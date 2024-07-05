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
        // #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        // #endif
    }

vector<int> topologicalSortBFS(int v, int e, vector<vector<int>> &edges){
    unordered_map<int, list<int>> adj;
    for(int i = 0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto n: adj[front]){
            indegree[n]--;
            if(indegree[n] == 0){
                q.push(n);
            }
        }
    }
    return ans;
}


vector<int> topologicalSortDFS(int v, int e, vector<vector<int>> &edges){
    unordered_map<int, list<int>> adj;
    for(int i = 0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    vector<bool> visited(v, false);
    stack<int> s;
    for(int i = 0;i<v;i++){
        if(!visited[i]){
            topologicalUtilDFS(i, adj, visited, s);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

void topologicalUtilDFS(int node, unordered_map<int,list<int>> &adj, vector<bool> &visited, stack<int> &st){
    visited[node] = true;
    for(auto i: adj[node]){
        if(!visited[i]){
            topologicalUtilDFS(i, adj, visited, st);
        }
    }
    st.push(node);
}





int main(){
    // i_o_f();
    int v, e;
    cin>>v>>e;
    vector<vector<int>> edges(e, vector<int>(2));
    f(e){
        cin>>edges[i][0]>>edges[i][1];
    }
    vector<int> ans = topologicalSortBFS(v, e, edges);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    ans = topologicalSortDFS(v, e, edges);
    for(auto i: ans){
        cout<<i<<" ";
    }

return 0;
}