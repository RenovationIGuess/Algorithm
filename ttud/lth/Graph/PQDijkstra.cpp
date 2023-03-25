// Implement dijkstra using priority_queue
#include <bits/stdc++.h>
#define INF (int)1e9
#define N 100005
#define pii pair<int, int>
using namespace std;

// priority_queue() { pq }
// for v in A[s] do {
//     d[v] = w(s, v); p[v] = s;
//     pq.push(v, d[v]);
// }

// while (!pq.empty()) {
//     (u, d[u]) = pq.pop();
//     if (u == t) break;
//     for (v in A[u]) {
//         if (d[v] > d[u] + w[u, v]) then
//             d[v] = d[u] + w[u, v]; p[v] = u;
//             pq.push(v, d[v]);
//     }
// }

struct Arc {
    int node; int w;
    Arc(int _node, int _w) {
        this->node = _node;
        this->w = _w;
    }
};

int n, m, s, t;
int d[N];
int p[N];
vector<Arc> A[N];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[u].push_back(Arc(v, w));
    }

    scanf("%d%d", &s, &t);
}

void DijkstraPrioriyQueue() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    for (int v = 1; v <= n; ++v) {
        d[v] = INF; p[v] = s;
    }
    // first -> key, second is the node

    for (int i = 0; i < A[s].size(); ++i) {
        Arc a = A[s][i];
        int v = a.node;
        int w = a.w;
        d[v] = w;
        p[v] = s;
        pq.push(make_pair(d[v], v));
        // cout << dd << " v: " << v << "  d[v]: " << d[v] << endl;
    }

    d[s] = 0;

    while (!pq.empty()) {
        pii e = pq.top();
        pq.pop();
        // int du = e.first;
        int u = e.second;
        // cout << u << endl;
        if (u == t) break;
        for (int i = 0; i < A[u].size(); ++i) {
            Arc a = A[u][i];
            int v = a.node;
            // cout << v << endl;
            int w = a.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                pq.push(make_pair(d[v], v));
                //cout << "v: " << v << "  d[v]: " << d[v] << endl;
            }
        }
    }

    cout << d[t] << endl;
}

int main() {
    input();
    DijkstraPrioriyQueue();
    return 0;
}