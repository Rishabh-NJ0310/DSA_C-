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


bool cmp(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}
void makeset(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0;i<n;i++){
    parent[i] = i;
    rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int n){
    if(parent[n] == n){
    return n;
    }
    return parent[n] = findParent(parent, parent[n]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
    parent[u] = v;
    }else if(rank[v] < rank[u]){
    parent[v] = u;
    }else{
    parent[v] = u;
    rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    /*
    Don't write main().
    Don't read input, it is passed as function argument.    
    No need to print anything.
    Taking input and printing output is handled automatically.
  */
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeset(parent,rank, n);
    int minw = 0;
    for(int i=0;i<edges.size();i++){
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int w = edges[i][2];
    if(u != v){
        minw += w;
        unionSet(u, v, parent, rank);
        }
    }
    return minw;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<int>> edges;
    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.push_back({u, v, w});
    }
    cout<<minimumSpanningTree(edges, n)<<endl;
    return 0;
}