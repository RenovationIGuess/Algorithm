#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int MAX = 1e5 + 1;

int n;
int m, cnt; 
bool check;
//m - max - do dai duong di dai nhat
//cnt - count - dem do dai duong di
//ban dau cnt + 1 se = 0 do chua co duong di nao 
int visited[MAX], pre[MAX], post[MAX];
vector<int> a[MAX];

void dfs(int u, int v, int cnt) { 
	check = false;
	//backtracking
	visited[u] = 1;
	for(int i = 0; i < a[u].size(); i++) {
		if(visited[a[u][i]] == 0) {
			pre[a[u][i]] = u;
			if(a[u][i] == v) {
				if(cnt + 1 > m) {
					m = cnt + 1;
					check = true;
					//break;
					continue;
				}
			} else dfs(a[u][i], v, cnt + 1);
			
			//if(check == false) 
			visited[a[u][i]] = 0; 
			pre[a[u][i]] = 0;
			//back tracking
		}
	}
}

void maxlength(int u, int v) {
	for(int i = 1; i <= n; i++) {
		visited[i] = 0;
		pre[i] = 0;
	}
	m = -1; cnt = 0;
	dfs(u, v, cnt);
	if(check = true) {
		cout << "Max length of " << u << " and " << v << " is " << m << "." << endl;
		/*int w = v;
		while(w != u) {
			post[pre[w]] = w;
			w = pre[w];
		}
		while(u != v) {
			cout << u << " -> ";
			u = post[u];
		} cout << v << endl; */
	} else cout << "No Path existed between " << u << " and " << v << "." << endl; 
	/*for(int i = 1; i <= n; i++) {
		cout << i << " " << pre[i] << " " << post[i] << endl;
	}*/
}

int main() {
	int m, u, v;
	cin >> n >> m; //>> u >> v;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	//maxlength(u, v);
	for(int i = 2; i <= n; i++) {
		maxlength(2, i);
	}
	
	return 0; 
}
