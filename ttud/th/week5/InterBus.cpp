#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
const int N = 5 * 1e3 + 2;
int n, k, m, dist[N], d[N], c[N];
vector<ii> New[N];
vector<int> Old[N];
priority_queue<ii, vector<ii>, greater<ii> > pq;
int dd[N];

void input() {
  int x, y;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d %d", &c[i], &d[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", &x, &y);
    Old[x].push_back(y);
    Old[y].push_back(x);
  }
}

queue<int> hd;

void bfs(int root) {
  memset(dd, 0, sizeof(dd));
  int X, v;
  hd.push(root);
  while (!hd.empty()) {
    X = hd.front();
    hd.pop();
    if (dd[X] == d[root]) continue;
    for (int i = 0; i < int(Old[X].size()); ++i) {
      v = Old[X][i];
      if (dd[v] == 0 && v != root) {
        dd[v] = dd[X] + 1;
        New[root].push_back(ii(c[root], v));
        hd.push(v);
      }
    }
  }
}

void dijkstra() {
  int u, du, v;
  for (int i = 2; i <= n; ++i) dist[i] = 1e9;
  pq.push(ii(0, 1));
  while (!pq.empty()) {
    u = pq.top().second;
    du = pq.top().first;
    pq.pop();
    if (du != dist[u]) continue;
    for (int i = 0; i < int(New[u].size()); ++i) {
      v = New[u][i].second;
      if (dist[v] > dist[u] + New[u][i].first) {
        dist[v] = dist[u] + New[u][i].first;
        pq.push(ii(dist[v], v));
      }
    }
  }
}

void solve() {
  for (int i = 1; i <= n; ++i) bfs(i);
  dijkstra();
  cout << dist[n] << endl;
}

int main() {
  input();
  solve();
  return 0;
}
