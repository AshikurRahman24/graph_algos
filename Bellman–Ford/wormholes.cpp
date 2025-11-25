#include <bits/stdc++.h>
using namespace std;

int main() {

    int c;
    cin >> c;

    while (c--) {
        int n, m;
        cin >> n >> m;

        struct Edge {
            int u, v, w;
        };

        vector<Edge> edges(m);

        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }

       
        vector<int> dist(n, 0);

        
        for (int i = 0; i < n - 1; i++) {
            for (auto &e : edges) {
                if (dist[e.u] + e.w < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.w;
                }
            }
        }

       
        bool negative_cycle = false;
        for (auto &e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                negative_cycle = true;
                break;
            }
        }

        cout << (negative_cycle ? "possible" : "not possible") << "\n";
    }

    return 0;
}
