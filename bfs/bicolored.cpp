#include <bits/stdc++.h>
using namespace std;

bool fg;

void bfs(const vector<vector<int>>& g, int src) {
    int n = g.size();
    vector<char> c(n, 'w');
    queue<int> q;

    c[src] = 'g';
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (c[v] == 'w') {
                c[v] = (c[u] == 'g') ? 'b' : 'g';
                q.push(v);
            } else if (c[v] == c[u]) {
                fg = true;
                return; 
            }
        }
    }
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        int e;
        cin >> e;

        vector<vector<int>> g(n);
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        fg = false;  
        bfs(g, 0);

        if (fg) cout << "NOT BICOLORABLE." << endl;
        else    cout << "BICOLORABLE." << endl;
    }

    return 0;
}
