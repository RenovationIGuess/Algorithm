#include<bits/stdc++.h>
#define MAX 100
using namespace std;
int n, c = 1, r = 0; //c:clock, r: result - number of strongly connected components
int pre[MAX], post[MAX], p1[MAX]; 	//p1: peaks array
int visited[MAX];
vector<int> a[MAX]; vector<int> b[MAX]; vector<int> l[MAX]; //l: scc save 
void prev(int u) {
	pre[u] = c;
	c++;
}
void postv(int u) {
	post[u] = c;
	c++;
}
void explore(int u) {
	visited[u] = 1;
	prev(u);
	for(int i = 0; i < b[u].size(); i++) {
		if(visited[b[u][i]] == 0) explore(b[u][i]);
	}
	postv(u);
}
void dfs() {
	for(int i = 0; i < n; i++) {
		visited[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		if(visited[i] == 0) explore(i);
	}
}
void dfs2(int u) {
	visited[u] = 1;
	l[r].push_back(u);
	for(int i = 0; i < a[u].size(); i++) {
		if(visited[a[u][i]] == 0) dfs2(a[u][i]);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	/*freopen("inputltm.txt", "r", stdin);
	freopen("outputltm2.dot", "w", stdout); */
	int m; cin >> n >> m; 
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		b[y].push_back(x);
	}
	dfs();
	for(int i = 0; i < n; i++) {
		p1[i] = i;
	}
	//sort(post, post + n,std::greater<int>());
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(post[i] < post[j]) {
				swap(post[i], post[j]);
				swap(p1[i], p1[j]);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		visited[p1[i]] = 0;
	}
	for(int i = 0; i < n; i++) {
		if(visited[p1[i]] == 0) {
			r++; 
			dfs2(p1[i]);
		}
	}
	cout << r << endl;
	for(int i = 1; i <= r; i++) {
		for(int j = 0; j < l[i].size(); j++) {
			cout << l[i][j] << " ";
		}
		cout << endl; 
	}
	return 0;
}
