#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>>& g, vector<vector<int>>& cost, vector<int>& dis, vector<int>& parent, int src, int n){
    dis.assign(n, INT_MAX);
    parent.assign(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[src] = 0;
    pq.push({dis[src], src});

    while(!pq.empty()){
        pair<int, int> node = pq.top();
        pq.pop();

        int u = node.second;
        for(int i=0; i<g[u].size(); i++){

            int v = g[u][i];
            int w = cost[u][i];

            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                parent[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
}

void print_path(int src, int des, vector<int>& parent){

    if(des == src){
        cout << src << ' ';
        return;
    }

    if(parent[des] == -1){
        cout << "no path";
        return;
    }
    print_path(src, parent[des], parent);
    cout << des << ' ';
}

int main(){

    int n, e;
    cin >> n >> e;

    vector<vector<int>> g(n);
    vector<vector<int>> cost(n);
    vector<int> dis(n);
    vector<int> parent(n);
    unordered_set<int> s;

    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        s.insert(u);
        g[u].push_back(v);
        cost[u].push_back(w);
    }

    int src;
    cin >> src;

    dijkstra(g, cost, dis, parent, src, n);

    for(int i=0; i<n; i++) if(s.find(i) != s.end()) cout << dis[i] << ' '; 


    return 0;
}
