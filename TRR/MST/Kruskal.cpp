#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int MAX = 100, w_MAX = 1e3 + 1;
int n; 
int p[MAX];
int rank[MAX];
int visited[MAX];
int parent[MAX];
vector<pair<int, int> > a[MAX];
vector<int> b[MAX]; //X
priority_queue<pair<int, int> > q; //sort weight
int cost[MAX];
/*void visit() {
	for(int i = 1; i <= w_MAX; i++) {
		visited[i] = 0;
	}
}*/
void makeset(int u) {
	parent[u] = u;
	rank[u] = 0;
}
int find(int u) {
	while(u != parent[u]) {
		u = parent[u];
	}
	return u;
}
int PathC(int x) { //PathCompression
	if(x != parent[x]) parent[x] = PathC(parent[x]);
	return parent[x];
	/*or:
	if(x == parent[x]) return x;
	return parent[x] = PathCompression(parent[x]);
	*/
}
void union1(int u, int v) {
	int r1 = find(u);
	int r2 = find(v);
	if(r1 == r2) return;
	if(rank[r1] > rank[r2]) {
		parent[r2] = r1;
	} else {
		parent[r1] = r2;
		if(rank[r1] == rank[r2]) rank[r2] = rank[r1] + 1;
	}
}
void kruskal(int l) {
	//visit();
	for(int i = 1; i <= n; i++) {
		makeset(i);
	}
	cost[l] = 0;
	q.push(make_pair(-cost[l], l));
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < a[i].size(); j++) {
			int x = a[i][j].first;
			int z = a[i][j].second;
			q.push(make_pair(-z, x));
		}
	}
		while(!q.empty()) {
			int u = q.top().second; q.pop();
			for(int j = 0; j < a[u].size(); j++) {
				int v = a[u][j].first;
				int w = a[u][j].second;
				if(find(u) != find(v)) {
					b[u].push_back(v);
					b[v].push_back(u);
					union1(u, v);
				}
			}
		}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < b[i].size(); j++) {
			if(b[i][j]  >= i + 1) {
				cout << i << " " << b[i][j] << endl;
			}
		}
	}
} 
int main() {
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		a[x].push_back(make_pair(y, w));
		a[y].push_back(make_pair(x, w));
	}
	kruskal(1);
	/*for(int i = 1; i <= n; i++) {
		for(int j = 0; j < b[i].size(); j++) {
			if(b[i][j] >= i + 1) {
				cout << i << " -- " << b[i][j] << endl;
			}
		}
	} */
	return 0;
}
