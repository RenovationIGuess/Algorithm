#include<iostream>
#define MAX 1001
using namespace std;
int n, cc, c = 1; //number of peaks, connected components, c - clock
int ccnum[MAX];
int G[MAX][MAX];
int pre[MAX], post[MAX];
int visited[MAX];
void previsited(int u) 
{
	ccnum[u] = cc;
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
	cc = 0;
	for(int v = 0; v < n; v++) {
		visited[v] = 0;
	}
	for(int v = 0; v < n; v++) {
		if(visited[v] == 0) {
			cc++;
			explore(v);
		}
	}
}
int main() 
{
	int m; //number of edges
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			G[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		G[x][y] = G[y][x] = 1;
	}
	dfs();
	for(int i = 0; i < n; i++) {
		cout << i << ": " << ccnum[i] << endl;
	}
	for(int i = 0; i < n; i++) {
		cout << i << ": " << pre[i] << " -- " << post[i] << endl;
	}
	return 0;
}
