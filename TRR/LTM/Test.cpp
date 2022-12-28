#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define MAX 10
using namespace std;
int n;
vector<int> a[MAX];
int ids[MAX], low[MAX], onstack[MAX];
int id = 0;
stack<int> b;
void dfs(int u) {
	b.push(u);
	onstack[u] = 1;
	low[u] = ids[u] = id++;
	for(int i = 0; i < a[u].size(); i++) {
		if(ids[a[u][i]] == 0) dfs(a[u][i]);
		if(onstack[a[u][i]] == 1) low[u] = min(low[u], low[a[u][i]]); 
	}
	if(low[u] == ids[u]) {
		while(!b.empty()) {
			int v = b.top(); b.pop();
			onstack[v] = 0;
			low[v] = ids[u];
			if(v == u) break;
		}
	}
}
int main() {
	int m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	for(int i = 0; i < n; i++) {
		low[i] = ids[i] = onstack[i] = 0;
	}
	dfs(0);
	for(int i = 0; i < n; i++) {
		cout << i << " - " << ids[i] << " - " << low[i] << endl;
	}
	/*int id = 0, a, b;
	a = id++;
	cout << a << endl;
	b = ++id;
	cout << b; */
	return 0; 
}
