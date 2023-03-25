#include<bits/stdc++.h>
#define N 100001

using namespace std;

struct Edge {
    int node; // nut
    int w; // trong so
    Edge (int _node, int _w) {
        this->node = _node;
        this->w = _w;
    }
};

int n;
vector<Edge> A[N];
int d[N]; // khoang cach tu node dau tien

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[u].push_back(Edge(v, w));
        A[v].push_back(Edge(u, w));
    }
}

// return the node which is farthest from u
int BFS(int u) {
    queue<int> Q;
    for (int v = 1; v <= n; ++v) {
        d[v] = -1;
    }
    // mark u is visited
    d[u] = 0;
    Q.push(u);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        // Explore all the adjacent edges of A[v]
        for (int i = 0; i < A[v].size(); ++i) {
            Edge e = A[v][i];
            int x = e.node;
            int w = e.w;
            // If x is not visited
            if (d[x] == -1) {
                Q.push(x);
                d[x] = d[v] + w;
            }
        }
    }
    int maxD = 0;
    int sel_v = -1;
    for (int v = 1; v <= n; ++v) {
        if (d[v] > maxD) {
            maxD = d[v];
            sel_v = v;
        }
    }
    return sel_v;
}

void solve() {
    int s = 1;
    int x = BFS(s);
    int y = BFS(x);
    int ans = d[y];
    cout << ans << endl;
}

int main() {
    input();
    solve();
    return 0;
}