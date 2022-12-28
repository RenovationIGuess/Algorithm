#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
//peak first, weight or dist second
using namespace std;
const int MAX = 1000, oo = 1e3 + 5;
int n;
int dist[MAX], prev[MAX]; //distance and previous
vector<pair<int, int> > a[MAX];
//priority_queue<pair<int, int>, std::greater<int> > q; //queue from smallest to largest
void update(int u, int v, int l) {
	dist[v] = std::min(dist[v], dist[u] + l);
}
void Bellman_Ford(int u) {
	for(int i = 1; i <= n; i++) {
		dist[i] = oo;
		prev[i] = 0;
	}
	dist[u] = 0;
	for(int i = 1; i <= n - 1; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 0; k < a[j].size(); k++) {
				int v = a[j][k].first;	//j's near peak
				int l = a[j][k].second; //distance between j and its near peak
				update(j, v, l);
			}
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
	Bellman_Ford(1);
	for(int i = 1; i <= n; i++) {
		cout << i << " -- " << dist[i] << endl;
	}
	return 0;
}
