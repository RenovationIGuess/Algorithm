#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<time.h>
#define oo 1e3 + 2
using namespace std;
const int MAX = 1e3 + 1;
int n;
int cost[MAX], preve[MAX], visited[MAX];
vector<pair<int, int> > a[MAX];
priority_queue<pair<int, int> > q;
void Prim() {
	for(int i = 1; i <= n; i++) {
		cost[i] = oo;
		preve[i] = 0;
	}
	int u = 1 + rand() % (n + 1 - 1); //random 1 dinh thuoc [1;n]
	cost[u] = 0;
	//visited[u] = 1;
	q.push(make_pair(-cost[u], u));
	while(!q.empty()) {
		//int s = -q.top().first; //weight
		int v = q.top().second; //peak
		q.pop();
		visited[v] = 1;
		for(int i = 0; i < a[v].size(); i++) {
			//if(visited[a[v][i].first] == 0) {
				int l = a[v][i].second; //weight
				int k = a[v][i].first; //peak
				if(visited[k] == 0) {
					if(cost[k] > l) {
						//visited[k] = 1;
						cost[k] = l;
						preve[k] = v;
						q.push(make_pair(-cost[k], k));
					}
				}
				
			//}
		}
	}
}
void print() {
	Prim();
	for(int i = 1; i <= n; i++) {
		cout << i << " " << preve[i] << endl;
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
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	//Prim();
	print();
	/*for(int i = 1; i <= n; i++) {
		cout << preve[i] << " -- " << cost[i] << endl;
	}*/
	return 0;
}
