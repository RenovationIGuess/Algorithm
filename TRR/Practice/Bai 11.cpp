#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 100
using namespace std;
int n, cc, tmp;
vector<int> a[MAX]; 
int visited[MAX];
void explore(int u) {
	visited[u] = 1;
	for(int i = 0; i < a[u].size(); i++) {
		if(visited[a[u][i]] == 0) explore(a[u][i]);
	}
}
void dfs() {
	cc = 0;
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
	for(int i = 1; i <= n; i++) {
		if(visited[i] == 0) {
			cc++;
			explore(i);
		}
	}
}
void res() {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}
int check(int u) {
	visited[u] = 1;
	/*for(int i = 1; i <= n, i != u; i++) {
		visited[i] = 0;
	} */
	tmp = 0;
	for(int i = 1; i <= n; i++) {
		if(visited[i] == 0) {
			tmp++;
			explore(i);
		}
	}
	//return tmp;
	if(tmp > cc) return true;
	else return false; 
}
int main() {
	int m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs();
	/*cout << cc << endl;
	for(int i = 1; i <= n; i++) {
		res();
		cout << check(i) << endl;
	}*/
	for(int i = 1; i <= n; i++) {
		res();
		if(check(i)) cout << i << " ";
	}
	return 0;
}

