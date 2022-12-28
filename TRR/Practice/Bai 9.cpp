#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100
using namespace std;
int n;
bool check;
vector<int> a[MAX];
int visited[MAX];
void find(int u, int v) {
	if(u == v) {
		check = true;
		return;
	}
	visited[u] = 1;
	for(int i = 0; i < a[u].size(); i++) {
		if(visited[a[u][i]] == 0) find(a[u][i], v);
	}
}
void res() {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	int G[MAX][2];
	int q; //question
	cin >> q; 
	for(int i = 0; i < q; i++) {
		int k, l;
		cin >> k >> l;
		G[i][0] = k;
		G[i][1] = l;
	} 
	res();
	for(int i = 0; i < q; i++) {
		check = false;
		find(G[i][0], G[i][1]);
		if(check == true) cout << "Yes" << endl;
		else cout << "No" << endl;
		res();
	}
	return 0;
}
