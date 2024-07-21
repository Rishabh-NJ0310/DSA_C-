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

class Solution {
    private:
    vector<int> topo_sort(int n, unordered_map<int,list<int>> &adj){
    vector<int> indegree(n+1);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    queue<int> q;

    for(int i = 1;i<=n;i++){
        if(indegree[i] <= 0){
            q.push(i);
        }
    }

    vector<int> ans;
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cnt++;
        ans.push_back(front);
        for(auto nbr: adj[front]){
            indegree[nbr]--;
            if(indegree[nbr] <= 0){
                q.push(nbr);
            }
        }
    }
    return cnt == n ? ans : vector<int>();
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) {
        /*
        1. check cycle in the graph
        2. if not present than topological sort or kahn's algorithm
        3. build the matrix from the indexes of sorted vectors
        question -> row -> [[1,2],[3,2]], col -> [[2,1],[3,2]];
            TopoSort rows->  [1->3->2] || [3->1->2] both are valid 
                              0  1  2
            taking   rows->  [1->3->2] -> i
            TopoSort cols->  [3->2->1] -> j
                              0  1  2  
                                        [0,0,1]
                                        [3,0,0]
                                        [0,2,0]
        */
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int,list<int>> adjRow;
        unordered_map<int,list<int>> adjCol;
        
        for(int i=0;i<rowC.size();i++){
            int u = rowC[i][0];
            int v = rowC[i][1];

            adjRow[u].push_back(v);
        }

        for(int i=0;i<colC.size();i++){
            int u = colC[i][0];
            int v = colC[i][1];

            adjCol[u].push_back(v);
        }
        vector<int> row = topo_sort(k,adjRow);
        vector<int> col = topo_sort(k,adjCol);
        if(row.size() == 0 || col.size() == 0){
            return vector<vector<int>>();
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for(int i=0;i<k;i++){
            int data = row[i];
            for(int j=0;j<k;j++){
                if(row[i] == col[j]){
                    ans[i][j] = data;
                }
            }
        }
        return ans;
    }
};


int main(){
i_o_f();

return 0;
}