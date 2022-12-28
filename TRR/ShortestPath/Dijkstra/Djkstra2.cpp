#include<iostream>
#include<vector>
#include<queue>
#define MAX 100

using namespace std;

const int oo = 1e3 + 1;
int n;
int dist[MAX];
int prev[MAX], post[MAX];
priority_queue<pair<int, int> > q; //first - dists <=> keys, second - peaks 
vector<pair<int, int> > a[MAX]; //first - peaks, second - length

bool dijkstra(int u, int w) { //u - start, w - end
	for(int i = 1; i <= n; i++) {
		dist[i] = oo;
		prev[i] = 0;
	} 
	dist[u] = 0;
	q.push(make_pair(-dist[u], u));
	while(!q.empty()) {
		int s = -q.top().first;
		int v = q.top().second;
		q.pop();
		if(v == w) return true;
		for(int i = 0; i < a[v].size(); i++) {
			int c = a[v][i].first; //peaks
			int l = a[v][i].second; //weight or length between v and a[v][i].first
			if(dist[c] > s + l) {
				dist[c]= s + l;
				prev[c] = v;
				q.push(make_pair(-dist[c], c));
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
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m; 
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		a[x].push_back(make_pair(y, t));
		//a[y].push_back(make_pair(x, t));
	}
	for(int i = 1; i <= n; i++) {
		print(1, i);
	}
	for(int i = 1; i <= n; i++) {
		cout << i << " - " << dist[i] << endl;
	}
	return 0;
}
