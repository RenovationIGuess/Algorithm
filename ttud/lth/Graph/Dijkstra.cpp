#include <bits/stdc++.h>
#define INF (int)1e9
#define N 10001
using namespace std;

struct Arc {
    int node; int w;
    Arc(int _node, int _w) {
        this->node = _node;
        this->w = _w;
    }
};

int n, m;
int d[N];
int p[N];
vector<Arc> A[N];
int s, t;

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[u].push_back(Arc(v, w));
    }

    scanf("%d%d", &s, &t);
}

int selectMin(set<int> nonFixed) {
    // return the node of nonFixed having minimum d[v]

    int minD = INF; int sel_v = -1;

    for (set<int>::iterator it = nonFixed.begin(); it != nonFixed.end(); ++it) {
        int v = *it;
        if (d[v] < minD) {
            minD = d[v];
            sel_v = v;
        }
    }

    return sel_v;
}

void dijkstra() {
    set<int> nonFixed;

    for (int v = 1; v <= n; ++v) {
        d[v] = INF; p[v] = s;
    }

    for (int i = 0; i < A[s].size(); ++i) {
        Arc a = A[s][i];
        int v = a.node; int w = a.w;
        d[v] = w;
    }

    d[s] = 0;
    for (int v = 1; v <= n; ++v) if (v != s) nonFixed.insert(v);

    while(!nonFixed.empty()) {
        int u = selectMin(nonFixed);
        if (u == t) break;
        nonFixed.erase(u); // shortest path from s to u has been found
        for (int i = 0; i < A[u].size(); ++i) {
            Arc a = A[u][i];
            int v = a.node;
            int w = a.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }

    cout << d[t];
}

int main() {
    input();
    dijkstra();
    return 0;
}