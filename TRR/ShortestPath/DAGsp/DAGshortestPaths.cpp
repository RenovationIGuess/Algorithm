#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAX = 1e3 + 1, oo = 1e3 + 2;
int n, c;
int dist[MAX], preve[MAX], post[MAX], prev[MAX], visited[MAX], p[MAX]; //p - peaks
vector<pair<int, int> > a[MAX];
queue<int> q; //store topo
void update(int u, int v, int l) {
	dist[v] = std::min(dist[v], dist[u] + l);
}
void previsit(int u) {
	prev[u] = c;
	c++;
}
void postvisit(int u) {
	post[u] = c;
	c++;
}
void explore(int u) {
	previsit(u);
	visited[u] = 1;
	for(int i = 0; i < a[u].size(); i++) {
		int s = a[u][i].first;
		if(visited[s] == 0) explore(s);
	}
	postvisit(u);
}
void dfs() {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(visited[i] == 0) explore(i);
	}
}
void topo() {
	dfs();
	for(int i = 1; i <= n; i++) {
		p[i] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(post[i] < post[j]) {
				swap(post[i], post[j]);
				swap(p[i], p[j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		q.push(p[i]);
	}
}
void DAG_shortest_paths(int u) {
	for(int i = 1; i <= n; i++) {
		dist[i] = oo;
		prev[i] = 0;
	}
	dist[u] = 0;
	topo();
	while(!q.empty()) {
		int s = q.front(); q.pop();
		for(int i = 0; i < a[s].size(); i++) {
			int k = a[s][i].first;
			int l = a[s][i].second;
			update(s, k, l);
		}
	}
}
int main() {
	int m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y, t; 
		cin >> x >> y >> t;
		a[x].push_back(make_pair(y, t));
	}
	DAG_shortest_paths(1);
	for(int i = 1; i <= n; i++) {
		cout << i << " -- " << dist[i] << endl;
	}
	return 0;
}
