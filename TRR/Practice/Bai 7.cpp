#include<bits/stdc++.h>
#define MAX 100
using namespace std;
vector<int> a[MAX];
int n;
int visited[MAX];
int preve[MAX];
void dfs2(int u, int v) {
	if(u == v) return;
	visited[u] = 1;
	for(int i = 0; i < a[u].size(); i++) {
		if(visited[a[u][i]] == 0) {
			preve[a[u][i]] = u;
			dfs2(a[u][i], v);
		}
	}
}
void print(int u, int v) {
	while(v != u) {
		cout << v << " ";
		v = preve[v];
	} cout << u;
}
int main() {
	int u, v, m; cin >> n >> m >> u >> v;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	dfs2(u, v);
	print(u, v);
	return 0;
}

