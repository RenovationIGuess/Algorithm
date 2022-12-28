#include<iostream>
#define MAX 100
using namespace std;
int n, c = 1, l; //number of peaks, connected components, c - clock, l - number of 
int ccnum[MAX];
int G[MAX][MAX];
int pre[MAX], post[MAX];
int visited[MAX];
int prev[MAX]; //previous
void previsited(int u) 
{
	pre[u] = c;
	c++;
}
void postvisited(int u) 
{
	post[u] = c;
	c++;	
}
void explore(int v) {
	visited[v] = 1;
	previsited(v);
	for(int u = 0; u < n; u++) {
		if(G[v][u] == 1) {
			if(visited[u] == 0) explore(u);
		} 
	}
	postvisited(v);
}
void dfs() {
	for(int v = 0; v < n; v++) {
		visited[v] = 0;
	}
	for(int v = 0; v < n; v++) {
		if(visited[v] == 0) {
			explore(v);
		}
	}
}
bool check(int u, int v) {
	if(pre[u] > pre[v] && post[u] < post[v]) {
		return true;
	}
	return false;
}
void dfs2(int u, int d) {
	if(visited[d] ==  1) return;
	visited[u] = 1;
	for(int v = 0; v < n; v++) {
		if(G[u][v] == 1 && visited[v] == 0) {
			prev[v] = u;
			dfs2(v, d);
		}
	}
}
void trace(int u, int v) {
	while(v != u) {
		cout << v << " <- ";
		v = prev[v];
	} cout << v << endl;
}
int main() {
	freopen("test.txt", "r", stdin);
	freopen("outtest.dot", "w", stdout);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			G[i][j] = 0;
		}
	}
	int m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		G[x][y] = 1;
	}
	dfs();
	for(int i = 0; i < n; i++) {
		cout << i << ": " << pre[i] << " -- " << post[i] << endl;
	}
	for(int i = 0; i < n; i++) {
		visited[i] = 0;
	}
	for(int u = 0; u < n; u++) {
		for(int v = 0; v < n; v++) {
			if(check(u, v) && G[u][v] == 1) {
				if(u < v) {
					cout << u << " <- ";
					dfs2(u, v);
					trace(u, v);
					
				} else {
					cout << v << " <- ";
					dfs2(v, u);
					trace(v, u);
				}
			}
		}
	} 
	/*for(int u = 0; u < n; u++) {
		for(int v = 0; v < n; v++) { 
			if(G[u][v] == 1 && check(u , v)) {
				cout << u << " - " << v << endl;
			}
		}
	} */
	return 0;
}

