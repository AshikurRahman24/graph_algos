#include <bits/stdc++.h>
using namespace std;

void bellmanford(vector<vector<int>> &g, vector<vector<int>> &cost, vector<int> &dis, vector<int> &parent, int src, int n)
{

    dis.assign(n, INT_MAX);
    parent.assign(n, -1);
    dis[src] = 0;

    for (int k = 0; k < n - 1; k++)
    {
        for (int i = 0; i < n; i++)
        {
            int u = i;
            for (int j = 0; j < g[u].size(); j++)
            {
                int v = g[u][j];
                int w = cost[u][j];

                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    parent[v] = u;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int u = i;
        if (dis[u] == INT_MAX)
            continue;
        for (int j = 0; j < g[u].size(); j++)
        {
            int v = g[u][j];
            int w = cost[u][j];

            if (dis[v] > dis[u] + w)
            {
                cout << "-ne cycle is ditected" << endl;
            }
        }
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    vector<vector<int>> g(n), cost(n);
    vector<int> dis(n), parent(n);
    unordered_set<int> s;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back(v);
        cost[u].push_back(w);
        s.insert(u), s.insert(v);
    }

    int src;
    cin >> src;

    bellmanford(g, cost, dis, parent, src, n);

    for (int i = 0; i < dis.size(); i++)
        cout << dis[i] << ' ';

    cout << endl;
    vector<int> path;
    int tg = 4;
    for (int i = tg; i != -1; i = parent[i])
        path.push_back(i);

    reverse(path.begin(), path.end());

    for (int i : path)
        cout << i << ' ';

    return 0;
}
