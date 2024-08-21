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

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1, 1e8);
    dist[src] = 0;

    for(int i=0;i<n-1;i++){
        // traverse on edges list
        for(auto j:edges){
            int u = j[0];
            int v = j[1];
            int w = j[2];

            if(dist[u] != 1e9 && ((dist[u]+w)< dist[v])){
                dist[v] = dist[u]+w;
            }
        }
    }
    
    for(auto j:edges){
            int u = j[0];
            int v = j[1];
            int w = j[2];

            if(dist[u] != 1e9 && ((dist[u]+w)< dist[v])){
                return {-1};
            }
        }
    return dist;
}
int main(){

i_o_f();
int n,m;
cin>>n>>m;
vector<vector<int>> edges;
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges.push_back({u,v,w});
}
int src;
cin>>src;
vector<int> ans = bellmonFord(n,m,src,edges);
for(auto i:ans){
    cout<<i<<" ";
}

return 0;
}