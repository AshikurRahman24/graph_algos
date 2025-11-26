#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs(int sx, int sy, int tx, int ty) {
    if (sx == tx && sy == ty) return 0;

    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int,int>> q;

    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        pair<int, int> node = q.front();
        int x = node.first;
        int y = node.second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;

                if (nx == tx && ny == ty)
                    return dist[nx][ny];

                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    string a, b;

    while (cin >> a >> b) {
        int sx = a[1] - '1';
        int sy = a[0] - 'a';
        int tx = b[1] - '1';
        int ty = b[0] - 'a';

        int moves = bfs(sx, sy, tx, ty);

        cout << "To get from " << a << " to " << b 
             << " takes " << moves << " knight moves." << endl;
    }
}
