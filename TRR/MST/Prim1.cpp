#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<time.h>
using namespace std;

const int MAX = 1e6 + 1;

int n;
int cost[MAX], previ[MAX], visited[MAX];
priority_queue<pair<int, int> > q;
vector<pair<int, int> > a[MAX];

void prim() {
	for(int i = 1; i <= n; i++) {
		cost[i] = MAX;
		previ[i] = 0;
		visited[i] = 0;
	}
	int u = 1; cost[u] = 0;
	/*int u = rand() % (n + 1 - 1) + 1;
	cost[u] = 0; */
	//visited[u] = 1;
	q.push(make_pair(-cost[u], u));
	while(!q.empty()) {
		int v = q.top().second; q.pop();
		visited[v] = 1;
		for(int i = 0; i < a[v].size(); i++) {
			int s = a[v][i].first;
			int c = a[v][i].second;
			if(visited[s] == 0) {
				if(cost[s] > c) { //&& visited[s] == 0
					cost[s] = c;
					previ[s] = v;
					//visited[s] = 1;
					q.push(make_pair(-cost[s], s));
				}	
			}	
		}
	}
	int num = 0;
	for(int i = 1; i <= n; i++) {
		num += cost[i];
	} cout << num << endl; // << " " << u << endl;
	for(int i = 1; i <= n; i++) {
		cout << i << " " << previ[i] << " " << cost[i] << endl;
	}
}
int main() {
	srand((int)time(0));
	int m; 
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		a[x].push_back(make_pair(y, w));
		a[y].push_back(make_pair(x, w));
	}
	prim();
	return 0;
}
