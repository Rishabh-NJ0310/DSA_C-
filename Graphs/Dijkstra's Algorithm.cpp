#include <bits/stdc++.h> 
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    //adj
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto i: vec){
        int u = i[0];
        int v = i[1];
        int w = i[2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<int> distance(vertices);
    for(int i=0;i<vertices;i++){
        distance[i] = INT_MAX;
    }
    set<pair<int,int>> st;
    distance[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        auto top = *st.begin();
        int nodeDist = top.first;
        int topNode = top.second;
        st.erase(st.begin());

        for(auto i: adj[topNode]){
            if((nodeDist + i.second) < distance[i.first]){
                auto record = st.find(make_pair(distance[i.first], i.first));
                if(record != st.end()){
                    st.erase(record);
                }
                distance[i.first] = nodeDist + i.second;

                st.insert(make_pair(distance[i.first], i.first));
            }
        }
    }
    return distance;
}

int main(){
    int v, e;
    cin>>v>>e;
    vector<vector<int>> edges(e, vector<int>(3));
    for(int i = 0;i<e;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    int source;
    cin>>source;
    vector<int> ans = dijkstra(edges, v, e, source);
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}