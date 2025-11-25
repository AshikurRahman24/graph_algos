#include <bits/stdc++.h>
using namespace std;


struct Edge {
    int u, v, w;
};

bool bellmanFord(int n, int src, vector<Edge>& edges, vector<int>& dist, vector<int>& parent) {
    dist.assign(n, INT_MAX);
    parent.assign(n, -1);

    dist[src] = 0;

 
    for (int i = 1; i <= n - 1; i++) {
        bool changed = false;

        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                changed = true;
            }
        }

   
        if (!changed) break;
    }

   
    for (auto &e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            return false; 
        }
    }

    return true; 
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges(e);

    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    vector<int> dist(n), parent(n);

    if (!bellmanFord(n, src, edges, dist, parent)) {
        cout << "Negative Weight Cycle Detected\n";
        return 0;
    }

    cout << "Distances:\n";
    for (int i = 0; i < n; i++)
        cout << "Node " << i << " : " << dist[i] << "\n";

    return 0;
}
