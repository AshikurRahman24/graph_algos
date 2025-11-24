#include <bits/stdc++.h>
using namespace std;

void bfs(const vector<vector<int>>& g, int src, vector<int>& dis, vector<int>& parent){

    int n = g.size();

    vector<char> c(n, 'w');
    dis.assign(n, INT_MAX);
    parent.assign(n, -1);

    queue<int> q;

    c[src] = 'g';
    dis[src] = 0;
    q.push(src);

    while(!q.empty()){
        int u = q.front();
        q.pop();
    
        for(int v : g[u]){
            if(c[v] == 'w'){
                c[v] = 'g';
                dis[v] = dis[u]+1;
                parent[v] = u;
                q.push(v);
            }
        }
        c[u] = 'b';
        cout << u << ' ';
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

    for(int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int s;
    cin >> s;

    vector<int> dis(n), parent(n);

    bfs(g, s, dis, parent);

    cout << endl;

    cout << dis[5] << endl;
    print_path(s, 5, parent);

    return 0;
}
