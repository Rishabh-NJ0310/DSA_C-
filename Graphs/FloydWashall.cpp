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

void floydWarshall(vector<vector<int>> &graph, int V){
    vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j){
                dist[i][j] = 0;
            }
            else if(graph[i][j] != 0){
                dist[i][j] = graph[i][j];
            }
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
i_o_f();

return 0;
}