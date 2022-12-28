#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 100
#define oo 1000
/* Test:
Input	Output
5 7		1 -- 0
1 2 2	2 -- 2
1 3 1	3 -- 1
2 3 1	4 -- 4 
2 4 2	5 -- 5
2 5 3
3 5 4
4 5 2
*/
using namespace std;
int n;
int dist[MAX];
int prev[MAX], post[MAX];
vector<int> a[MAX];
int G[MAX][MAX]; //l(u, v)
priority_queue<int> q;
//queue<int> q1;
int check(int s) {
	for(int i = 1; i <= n; i++) {
		if(s == dist[i]) return i;
	}
}
bool dijkstra(int u, int w) { //u = 1
	for(int i = 1; i <= n; i++) {
		dist[i] = oo; //dist[1] -> dist[n] = oo
		prev[i] = 0;  //all peaks have no prev yet
	}
	dist[u] = 0; //dist[1] = 0
	q.push(-dist[u]);
	while(!q.empty()) {
		int s = -q.top(); q.pop(); //s = 0; 0 bi xoa
		int v = check(s);
		if(v == w) return true;
		for(int i = 0; i < a[v].size(); i++) {
			if(dist[a[v][i]] > s + G[v][a[v][i]])	{
				dist[a[v][i]] = s + G[v][a[v][i]];
				prev[a[v][i]] = v;
				q.push(-dist[a[v][i]]);
			}
		}
	}
	return false;
}
void print(int u, int v) {
	if(dijkstra(u, v)) {
		int tmp = v;
		while(tmp != u) {
			post[prev[tmp]] = tmp;
			tmp = prev[tmp];
		}
		while(u != v) {
			cout << u << " -> ";
			u = post[u];
		} cout << v << ": " << dist[v] << endl; 	
	} else cout << "No Path!" << endl;
}
int main() {
	int m; cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			G[i][j] = oo;
		}
	}
	for(int i = 0; i < m; i++) {
		int x, y, t; //peak, peak, dist
		cin >> x >> y >> t;
		a[x].push_back(y);
		a[y].push_back(x); 
		G[x][y] = G[y][x] = t;
	}  
	for(int i = 1; i <= n; i++) {
		print(1, i);
	}
	return 0;
}
