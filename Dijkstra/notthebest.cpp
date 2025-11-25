// https://lightoj.com/problem/not-the-best
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Node {
    int v;
    long long w;
};

struct State {
    int u;
    long long dist;

    bool operator<(const State& other) const {
        return dist > other.dist; 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        int N, R;
        cin >> N >> R;

        vector<vector<Node>> g(N + 1);

        while (R--) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }

        vector<long long> dist1(N + 1, INF);
        vector<long long> dist2(N + 1, INF);

        priority_queue<State> pq;

        dist1[1] = 0;
        pq.push({1, 0});

        while (!pq.empty()) {
            State node = pq.top();
            pq.pop();
            int d = node.dist;
            int u = node.u;

            if (d > dist2[u]) continue;

            for (auto &edge : g[u]) {
                int v = edge.v;
                long long w = edge.w;
                long long nd = d + w;

                if (nd < dist1[v]) {
                    dist2[v] = dist1[v];
                    dist1[v] = nd;
                    pq.push({v, nd});
                }
                else if (nd > dist1[v] && nd < dist2[v]) {
                    dist2[v] = nd;
                    pq.push({v, nd});
                }
            }
        }

        cout << "Case " << tc << ": " << dist2[N] << "\n";
    }

    return 0;
}
