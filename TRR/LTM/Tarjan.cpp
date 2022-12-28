#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
const int MAX = 1e3 + 1;
int n, id = 1, scc = 0; //scc - ltm
int ids[MAX], low[MAX], onstack[MAX]; //low - low link, onstack - check is on stack or not
vector<int> a[MAX];
stack<int> b;
void dfs(int u) {
	b.push(u);
	//visited[u] = 1;
	ids[u] = low[u] = id++;
	onstack[u] = 1;
	for(int i = 0; i < a[u].size(); i++) {
		if(ids[a[u][i]] == 0) dfs(a[u][i]); //goi de quy xog moi xet xuong duoi
		if(onstack[a[u][i]] == 1) low[u] = min(low[u], low[a[u][i]]);
	}
	if(ids[u] == low[u]) {
		while(!b.empty()) {
			int v = b.top(); b.pop();
			onstack[v] = 0;
			low[v] = ids[u];
			if(v == u) break;
		}
		scc++;
	}
}
void tarjan() {
	for(int i = 1; i <= n; i++) {
		ids[i] = 0;
		low[i] = 0;
		onstack[i] = 0;
		//visited[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(ids[i] == 0) dfs(i);
	}
	//return scc;
}
int main() {
	int m; 
	int previ[MAX];
	previ[low[1]] = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}
	tarjan(); 
	int max = low[1], l = scc;
	cout << l << endl;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(max < low[j]) {
				previ[low[j]] = max;
				max = low[j];
			}
		}
	} //cout << max << endl;
	for(int i = 1; i <= n; i++) {
		cout << i << " - " << low[i] << endl;
	}
	while(max != 0) {
		for(int i = 1; i <= n; i++) {
			if(low[i] == max) {
				cout << i << " "; 
			}
		}
		cout << endl;
		max = previ[max];
	} 
	return 0;
}
