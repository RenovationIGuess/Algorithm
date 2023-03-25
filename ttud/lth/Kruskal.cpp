#include <bits/stdc++.h>
#define N 100001
#define MOD (int)1e9

using namespace std;

int n, m;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) {
        this->u = _u;
        this->v = _v;
        this->w = _w;
    }
};

vector<Edge> edges;

int W = 0; // result - weight of the MST
int p[N], r[N]; // p - parent, r - rank

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Edge e = Edge(u, v, w);
        edges.push_back(e);
    }
}

bool compare(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int findParent(int u) {
    if (p[u] == u) return u;
    p[u] = findParent(p[u]);
    return p[u];
}

void unify(int x, int y) {
    if (r[x] > r[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (r[x] == r[y]) {
            r[y]++;
        }
    }
}

void makeSet(int x) {
    p[x] = x;
    r[x] = 0;
}

void solve() {
    sort(edges.begin(), edges.end(), compare);

    vector<Edge> TE; // tap canh cua MST

    for (int i = 1; i <= n; ++i) {
        makeSet(i);
    }

    for (Edge e : edges) {
        int pu = findParent(e.u);
        int pv = findParent(e.v);
        if (pu != pv) {
            unify(pu, pv);
            TE.push_back(e);
            W += e.w;
        }
    }

    cout << W % MOD << endl;
}

int main() {
    input();
    solve();
    return 0;
}