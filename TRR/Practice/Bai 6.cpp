#include<bits/stdc++.h>
#define MAX 100 
using namespace std;
int n;
vector<int> a[MAX];
int visited[MAX];
void bfs(int v) {
	visited[v] = 1;
	queue<int> q;
	q.push(v);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		cout << u << " ";
		for(int i = 0; i < a[u].size(); i++) {
			if(visited[a[u][i]] == 0) {
				visited[a[u][i]] = 1;
				q.push(a[u][i]);
			}
		}
	}
}
int main() {
	int u, m; cin >> n >> m >> u;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x); 
	}
	bfs(u);
	return 0;
}
