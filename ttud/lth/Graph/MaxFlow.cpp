#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;
int n, m;
int s, t;
int parent[N]; // Parent[v] is the parent of v in the BFS for finding augmenting path
int f[N][N]; // f[u][v] is the current flow on arc(u, v)
int c[N][N]; // c[u, v] is the capacity of arc(u, v)
vector<int> Adj[N];
int ans; // value of the max-flow found

void input() {
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            c[i][j] = 0;
        }
    }

    for (int k = 1; k <= m; ++k) {
        int u, v, w;
        cin >> u >> v >> w;
        c[u][v] = w;
        Adj[u].push_back(v);
    }
}

bool findBFSPath() {
    queue<int> Q;
    memset(parent, 0, sizeof(parent));
    Q.push(s);

    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int i = 0; i < Adj[u].size(); ++i) {
            int v = Adj[u][i];
            if (parent[v] == 0) {
                bool ok = false;
                if (c[u,v] > 0) {
                    if (f[u][v] < c[u][v]) ok = true;
                } else {
                    // Cung nguoc
                    if (f[v][u] > 0) ok = true;
                }

                if (ok) {
                    parent[v] = u; Q.push(v);
                    if (v == t) return true;
                }
            }
        } 
    }
    return false;
}

void augmentFlow() {
    int u = t; 
    int delta = 1e9;
    while (parent[u] != 0) {
        int pu = parent[u];
        if (c[pu][u] > 0) {
            delta = min(delta, c[pu][u] - f[pu][u]);
        } else {
            delta = min(delta, f[u][pu]);
        }
        u = pu;
    }

    ans += delta; // value of the max-flow is augmented by delta
    // Update flow along the augmenting path
    u = t;
    while (parent[u] != 0) 
    {
        int pu = parent[u];
        if (c[pu][u] > 0) {
            f[pu][u] = f[pu][u] + delta;
        } else {
            f[u][pu] = f[u][pu] - delta;
        }
        u = pu;
    }
}

void maxFlow() {
    // init 0-flow
    for (int u = 1; u <= n; ++u) {
        for (int i = 0; i < Adj[u].size(); ++i) {
            int v = Adj[u][i];
            if (c[u][v] > 0) f[u][v] = 0;
        }
    }

    ans = 0;
    while(true) {
        bool ok = findBFSPath();
        if (!ok) break;
        // augment flow along the path
        augmentFlow();
    }

    cout << ans << endl;
}

int main() {
    input();
    maxFlow();
    return 0;
}