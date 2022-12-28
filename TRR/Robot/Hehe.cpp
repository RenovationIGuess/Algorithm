#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define oo 1e9 + 1
using namespace std;

const int MAX = 100;
int n;
int r;
int a, b, c, d;

//vector<pair<int, int> > m[MAX];
vector<pair<int, int> > t[MAX*MAX];
int previous[MAX*MAX];
int post[MAX*MAX];
int dist[MAX*MAX];
int shortest[MAX][MAX];

void Floyd() {
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(shortest[i][j] > shortest[i][k] + shortest[k][j]) {
					shortest[i][j] = shortest[i][k] + shortest[k][j];
				} 
			}
		}
	}
}

/*int shortestPath(int u, int v) {
	for(int i = 0; i < n; i++) {
		dist1[i] = oo;
	}
	priority_queue<pair<int, int> > q1;
	dist1[u] = 0;
	q1.push(make_pair(u, -dist1[u]));
	while(!q1.empty()) {
		int s = q1.top().first; 
		int l = -q1.top().second;
		q.pop();
		for(int i = 0; i < t[s].size(); ++i) {
			if(dist1[t[s][i].first] > l + t[s][i].second) {
				dist1[t[s][i].first] = l + t[s][i].second;
				q.push(make_pair(t[s][i].first, -dist1[t[s][i].first]));
			}
		}
	}
	
} */

void djikstra(int u, int v) {
	bool check = false;
	for(int i = 0; i < n * 100; ++i) {
		dist[i] = oo;
	}
	priority_queue<pair<int, int> > q;
	previous[u] = -1;
	dist[u] = 0;
	q.push(make_pair(u, -dist[u]));
	/*for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << shortest[i][j] << " ";
		}
		cout << endl;
	} */
	while(!q.empty()) {
		/*int s = q.top().first; 
		int l = -q.top().second;
		q.pop();
		for(int i = 0; i < t[s].size(); ++i) {
			if(dist[t[s][i].first] > l + t[s][i].second) {
				dist[t[s][i].first] = l + t[s][i].second;
				previous[t[s][i].first] = s;
				if(t[s][i].first == v) return;
				q.push(make_pair(t[s][i].first, -dist[t[s][i].first]));
			}
		}*/
		int s = q.top().first; 
		int x = s / 100;
		int y = s % 100;
		//cout << x << " " << y << endl;
		int l = -q.top().second;
		q.pop();
		if(s == v) {
			check = true;
			break;
		}
		for(int i = 0; i < t[y].size(); ++i) {
			int ya = t[y][i].first;
			//cout << x << " " << ya << " " << shortest[ya][x] << endl;
			int yb = t[y][i].second;
			if(shortest[ya][x] <= r) continue;
			int next = x * 100 + ya;
			
			if(dist[next] > l + yb) {
				dist[next] = l + yb;
				previous[next] = s;
				q.push(make_pair(next, -dist[next]));
			}
		} 
		for(int i = 0; i < t[x].size(); ++i) {
			int xa = t[x][i].first;
			int xb = t[x][i].second;
			if(shortest[xa][y] <= r) continue;
			int next = xa * 100 + y;
			
			if(dist[next] > l + xb) {
				dist[next] = l + xb;
				previous[next] = s;
				q.push(make_pair(next, -dist[next]));
			}
		}
	}
	if(check == true) {
		int tmp = v;
		while(tmp != u) {
			post[previous[tmp]] = tmp;
			tmp = previous[tmp];
		}
		while(u != v) {
			int ua = u / 100; 
			int ub = u % 100;
			cout << ua << " " << ub << "\t" << shortest[ua][ub] << endl;
			u = post[u];
		} 
		int va = v / 100;
		int vb = v % 100;
		cout << va << " " << vb << "\t" << shortest[va][vb];
	} else cout << "?" << endl; 
	/*while(v != u) {
		cout << v << " " << previous[v] << endl;
		v = previous[v];
	}*/
}

int main() {
	int m;
	cin >> n >> m;
 
	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < MAX; ++j) {
			if(i == j) shortest[i][j] = 0;
			else shortest[i][j] = oo; 
		}
	}
	for(int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		t[x].push_back(make_pair(y, w));
		t[y].push_back(make_pair(x, w));
		shortest[x][y] = shortest[y][x] = w;
	}
	cin >> a >> b >> c >> d;
	int st = a * 100 + b; //start
	int fi = c * 100 + d; //finish
	cin >> r;
	Floyd();
	/*for(int i = 0; i < n - 1; ++i) {
		for(int j = i; j < n; ++j) {
			cout << i << " - " << j << " -- " << shortest[i][j] << endl;
		}
	} */
	djikstra(st, fi);
	return 0;
}
