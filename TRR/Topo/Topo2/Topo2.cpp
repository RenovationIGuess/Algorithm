#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
int n, c = 1; //n: number of peaks, c: clock
int G[MAX][MAX];
int pre[MAX], post[MAX];
//int topo[MAX];
int visited[MAX];
int check[MAX];
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
    for(int v = 0; v < n; v++) {
        if(G[u][v] == 1 && visited[v] == 0) {
            explore(v);
        }
    }
    postv(u);
}
void dfs() {
    for(int u = 0; u < n; u++) {
        visited[u] = 0;
    }
    for(int u = 0; u < n; u++) {
        if(visited[u] == 0) explore(u);
    }
}
bool checkBackE(int u, int v) {
	if(pre[u] > pre[v] && post[v] > post[u]) return true;
	return false;
}
bool checkDAG() {
	for(int u = 0; u < n; u++) {
		for(int v = 0; v < n; v++) {
			if(G[u][v] == 1 && checkBackE(u, v)) {
				return false; //Because Back Edge exist
			}
		}
	}
	return true; //if not
}
bool checkS(int u) { //Check does u = source peak
	for(int v = 0; v < n; v++) {
		if(G[v][u] == 1) return false;
	}
	return true;
}
bool confirm() {
	for(int i = 0; i < n; i++) {
		if(check[i] == 0) return false;
	} 
	return true;
}
void topo() {
	queue<int> t; //topo
	for(int i = 0; i < n; i++) {
		check[i] = 0;
	}
	int i = 0;
	while(i < n) {
		if(confirm()) break;
		if(check[i] == 0 && checkS(i)) {
			check[i] = 1;
			for(int j = 0; j < n; j++) {
				if(G[i][j] == 1) G[i][j] = 0;
			}
			t.push(i);
			i = -1; 
		}
		i++;
	}
	while(!t.empty()) {
		int u = t.front(); t.pop();
		cout << u << " ";
	}
} 
int main() {
	freopen("topo2.txt", "r", stdin);
	freopen("topo2.dot", "w", stdout);
	for(int u = 0; u < MAX; u++) {
		for(int v = 0; v < MAX; v++) {
			G[u][v] = 0;
		}
	}
    int e; //number of edges
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        G[x][y] = 1;
    }
    dfs();
    if(checkDAG()) {
		topo();  		
	} else cout << "Can't use this algorithm";
	return 0;
}
    
