// https://codeforces.com/contest/20/problem/C

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n + 1);    

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w}); 
    }

    const long long INF = 1e18;
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();
        int d = node.first;
        int u = node.second;
        if (d != dist[u]) continue;  

        for (auto &edge : g[u]) {
            int v = edge.first;
            long long w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

 
    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    for (int cur = n; cur != -1; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";

    return 0;
}
