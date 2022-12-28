#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int n, c = 1; //c: clock
vector<int> a[MAX];
/*int pre[MAX], post[MAX]; */
int visited[MAX];
/*void prev(int v) {
	pre[u] = c;
	c++;
}
void postv(int v) {
	post[u] = c;
	c++;
} */
/*void explore(int v) {
	visited[v] = 1;
	prev(v);
	for(int i = 1; i <= n; i++) {
		if(a[i] && visited[i] == 0) explore(i); 
	}
	postv(v);
} */
/*void dfs() {
	for(int i = 1; i <= n; ++i) {
		visited[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(visited[i] == 0) explore(i);
	}
} */
void dfs2(int v) {
	visited[v] = 1;
	cout << v << " ";
	for(int i = 0; i < a[v].size(); i++) {
		if(visited[a[v][i]] == 0) dfs2(a[v][i]);
	}
}
int main() {
	int m, u; cin >> n >> m >> u;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	dfs2(u);
	return 0;
}
