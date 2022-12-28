#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 100
#define oo 1000 // => chi chay dc bai toan co flow <= 1000
using namespace std;

int s, t; //source and sink
int n; //number of peaks
int visited[MAX], previ[MAX];
int G[MAX][MAX], Gr[MAX][MAX];
 
 vector<int> a[MAX];
//vector<pair<int, int> > G[MAX]; //graph
//vector<pair<int, int> > Gr[MAX]; //residual graph

bool bfs(int s, int t) {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	previ[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		/*for(int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].first; */
		for(int v = 1;  v <= n; v++) {
			if(visited[v] == 0 && Gr[u][v] > 0) {
				q.push(v);
				previ[v] = u;
				visited[v] = 1;
			}	
		}
	}
	return (visited[t] == true);
}

int Ford_Fulkerson(int s, int t) {
	int u, v;
	int max_flow = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			Gr[i][j] = G[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(G[i][j] > 0) {
				G[i][j] = 0;
			}
		}
	}
	while(bfs(s, t)) {
		int path_flow = oo;
		for(v = t; v != s; v = previ[v]) {
			u = previ[v];
			path_flow = min(path_flow, Gr[u][v]);
		}
		for(v = t; v != s; v = previ[v]) {
			u = previ[v];
			Gr[u][v] -= path_flow;
			Gr[v][u] += path_flow;
			G[u][v] += path_flow;
		}
		max_flow += path_flow;
	}
	return max_flow;
}

int main() {
	int m; 
	cin >> n >> m >> s >> t;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		//G[x].push_back(make_pair(y, w));
		G[x][y] = w;
		a[x].push_back(y);
	}
	int result = Ford_Fulkerson(s, t);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(G[i][j] > 0) {
				cout << i << " -> " << j << ": " << G[i][j] << endl;
			}
		}
	}
	cout << "Max flow = " << result << endl;
	cout << "Min cut L = {" << s;
	for(int i = 0; i < a[s].size(); i++) {
		cout << ", " << a[s][i];
	} cout << "}";
	return 0;
}
