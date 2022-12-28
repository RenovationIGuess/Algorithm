#include<bits/stdc++.h>
#define MAX 100
using namespace std;
vector<int> a[MAX];
int n; 
int visited[MAX];
int preve[MAX];
void bfs(int u, int v) {
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty()) {
		int u = q.front(); q.pop(); 
		for(int i = 0; i < a[u][i]; i++) {
			if(visited[a[u][i]] == 0) {
				visited[a[u][i]] = 1;
				preve[a[u][i]] = u;
				q.push(a[u][i]);
			}
		}
	}
	while(v != u) {
		cout << v << " ";
		v = preve[v];
	} cout << u;
}
int main() {
	int u, v, m;
	cin >> n >> m >> u >> v;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	bfs(u, v);
	return 0;
}
