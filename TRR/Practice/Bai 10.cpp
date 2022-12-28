#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define MAX 100
using namespace std;
int n;
bool check;
vector<int> a[MAX];
int visited[MAX];
void bfs(int u, int v) {
	queue<int> q;
	visited[u] = 1;
	q.push(u);
	while(!q.empty()) {
		int s = q.front(); q.pop();
		if(s == v) {
			check = true;
			return;
		}
		for(int i = 0; i < a[s].size(); i++) {
			if(visited[a[s][i]] == 0) {
				q.push(a[s][i]);
				visited[a[s][i]] = 1;
			}
		}
	}
}
void res() {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}
int main() {
	int m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int G[MAX][2];
	int q; cin >> q;
	for(int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		G[i][0] = x;
		G[i][1] = y;
	}
	res();
	for(int i = 0; i < q; i++) {
		check = false;
		bfs(G[i][0], G[i][1]);
		if(check == true) cout << "Yes" << endl;
		else cout << "No" << endl;
		res();
	}
	return 0;
}
