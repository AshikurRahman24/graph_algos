#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v, w;
};

void prim(int n, vector<vector<Node>>& g, int src) {
    vector<int> key(n, INT_MAX);     
    vector<int> parent(n, -1);       
    vector<bool> inMST(n, false);    

   
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; 
        inMST[u] = true;

        
        for (auto &neigh : g[u]) {
            int v = neigh.v;
            int w = neigh.w;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

   
    cout << "Edges in MST:\n";
    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " (weight: " << key[i] << ")\n";
            total_cost += key[i];
        }
    }

    cout << "Total cost of MST = " << total_cost << "\n";
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<Node>> g(n);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

      
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int src;
    cin >> src;

    prim(n, g, src);

    return 0;
}
