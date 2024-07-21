#include <bits/stdc++.h>
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


void dfs(int node, unordered_map<int,bool> &vis, stack<int> &s,	unordered_map<int, list<int>> &adj ){
	vis[node] = true;
	for(auto n: adj[node]){
		if(!vis[n]){
			dfs(n, vis, s, adj);
		}
	}
	s.push(node);
}

void revdfs(int node, unordered_map<int,bool> &vis,	unordered_map<int, list<int>> &adj ){
	vis[node] = true;
	for(auto n: adj[node]){
		if(!vis[n]){
			revdfs(n, vis, adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
	unordered_map<int, list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}
	stack<int> s;
	unordered_map<int,bool> vis;

	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i, vis, s, adj);
		}
	}

	// transpose graph

	unordered_map<int, list<int>> transpose;
	for(int i=0;i<v;i++){
		vis[i] = 0;
		for(auto n: adj[i]){
			transpose[n].push_back(i);
		}
	}

	//dfs call for counting
	int count = 0;
	while(!s.empty()){
		int top = s.top();
		s.pop();
		if(!vis[top]){
			count++;
			revdfs(top,vis,transpose);
		}
	}
	return count;
}