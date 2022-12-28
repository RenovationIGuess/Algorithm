#include<iostream>
#include<queue>
#define MAX 100
using namespace std;
int n, c = 1; //n: number of peaks, c: clock
int G[MAX][MAX];
int pre[MAX], post[MAX];
int topo[MAX];
int visited[MAX];
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
void sort() {
    for(int u = 0; u < n; u++) {
        topo[u] = u;
    }
    for(int u = 0; u < n; u++) {
        int tmp, tmp2;
        for(int v = u + 1; v < n; v++) {
            if(post[u] < post[v]) {
            	tmp2 = post[u];
				post[u] = post[v];
				post[v] = tmp2; 	
                tmp = topo[u];
                topo[u] = topo[v];
                topo[v] = tmp; 
            }
        }
    }
}
int main() {
	freopen("test.txt", "r", stdin);
	freopen("result.dot", "w", stdout);
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
    sort();
    for(int i = 0; i < n; i++) {
        cout << topo[i] << " ";
    } cout << endl;  
    /*for(int i = 0; i < n; i++) {
    	cout << i << ": " << pre[i] << " -- " << post[i] << endl;
	} 
	for(int u = 0; u < n; u++) {
        topo[u] = u;
    }
    int tmp, tmp2;
    for(int u = 0; u < n; u++) {
        for(int v = u + 1; v < n; v++) {
            if(post[u] < post[v]) {
            	tmp2 = post[u];
				post[u] = post[v];
				post[v] = tmp2; 	
                tmp = topo[u];
                topo[u] = topo[v];
                topo[v] = tmp; 
            }
        }
    } 
    for(int i = 0; i < n; i++) {
    	cout << post[i] << " ";
	} cout << endl;
	for(int i = 0; i < n; i++) {
		cout << topo[i] << " ";
	} */
	/*queue<int> topo2;
	for(int u = 0; u < n; u++) {
		visited[u] = 0;
	}
	for(int u = 0; u < n; u++) {
		for(int v = 0; v < n; v++) {
			if(G[v][u] == 1 && visited[u] == 0) {
				visited[u] = 1;
				topo2.push(u);
			} 	
		}
	}
	while(!topo2.empty()) {
		int u = topo2.front(); topo2.pop();
		cout << u << " ";
	} */
    return 0;
}
